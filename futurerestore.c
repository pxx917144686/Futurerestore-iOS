#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <curl/curl.h> // 安装 libcurl
#include <regex.h>

struct MemoryStruct
{
	char* memory;
	size_t size;
};

// WriteMemoryCallback 函数：将内容写入 MemoryStruct，并重新分配内存
static size_t WriteMemoryCallback(void* contents, size_t size, size_t nmemb, void* userp) {
	size_t realsize = size * nmemb;
	struct MemoryStruct *mem = (struct MemoryStruct*) userp;

	char *ptr = realloc(mem -> memory, mem -> size + realsize + 1);
	if(!ptr) {
		printf("错误（内存）: realloc 返回 NULL");
		return 0;
	}

	mem -> memory = ptr;
	memcpy(&(mem -> memory[mem -> size]), contents, realsize);
	mem -> size = mem -> size + realsize;
	mem -> memory[mem -> size] = 0;

	return realsize;
}

// getLatestVersion 函数：发送 GET 请求到 GitHub Actions 页面，获取内容
struct MemoryStruct getLatestVersion(void) {
	curl_global_init(CURL_GLOBAL_ALL);
	CURL *curl = curl_easy_init();

	struct MemoryStruct chunk;

	chunk.memory = malloc(1);  // 初始分配内存
	chunk.size = 0;

	if(!curl) {
		fprintf(stderr, "Curl 初始化失败\n");
		exit(-1);
	}

	CURLcode res;
	curl_easy_setopt(curl, CURLOPT_URL, "https://github.com/futurerestore/futurerestore/actions");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void*) &chunk);
	res = curl_easy_perform(curl);

	if(res != CURLE_OK) {
		fprintf(stderr, "获取 URL 内容时出错\n");
		exit(-2);
	}

    curl_easy_cleanup(curl);
    curl_global_cleanup();

	return chunk;
}

// REQParser 函数：解析请求内容，提取并输出唯一的构建 URL
void REQParser(struct MemoryStruct chunk) {
	regex_t regex;
    regcomp(&regex, "/futurerestore/futurerestore/actions/runs/[0-9]+", REG_EXTENDED);
    
    regmatch_t match;
    const char* cursor = chunk.memory;
    const char* last_match = NULL;
    size_t last_match_length = 0;
    
    while (regexec(&regex, cursor, 1, &match, 0) == 0) {
        int begin = match.rm_so;
        int end = match.rm_eo;

        // 仅当当前匹配与上次匹配不同，才输出 URL
        if (!last_match || strncmp(last_match, cursor + begin, end - begin) != 0 || last_match_length != (size_t)(end - begin)) {
            printf("构建链接 : https://github.com%.*s\n", end - begin, cursor + begin);
            last_match = cursor + begin;
            last_match_length = end - begin;
        }

        cursor += end;
    }
    
    regfree(&regex);
}

int main(void) {
	struct MemoryStruct result = getLatestVersion();
	REQParser(result);
	free(result.memory);
	return 0;
}
