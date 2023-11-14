#include <stdio.h>
#include <string.h>

#define MAX_STR_LENGTH 100

// 函数声明
void readString(char *string, int string_size);
void printString(char *string);
int preprocessString(char *string, char *string_preprocessed);
int manacher(char *string, char *result, int str_len);

int main() {
    char string_input[MAX_STR_LENGTH];             // 存储输入的原始字符串
    char string_process[2 * MAX_STR_LENGTH + 3];   // 存储预处理后的字符串
    char result[MAX_STR_LENGTH];                   // 存储最长回文子串
    int str_len = 0;                               // 输入字符串的长度
    int max_len = 0;                               // 最长回文子串的长度

    printf("Type in the string. \nPress return to end the input: ");
    readString(string_input, sizeof(string_input));  // 从标准输入读取字符串
    printString(string_input);                      // 打印原始输入字符串

    str_len = preprocessString(string_input, string_process);  // 预处理输入字符串
    // printString(string_process);  // （可选）打印预处理后的字符串

    max_len = manacher(string_process, result, str_len);  // 使用Manacher算法找到最长回文子串
    if (max_len != 1) {
        printf("The longest palindrome we found has length %d. ", max_len);
        printString(result);  // 打印最长回文子串
    } else {
        printf("No palindrome has been found.\n");
    }

    printf("End of program.\n");

    return 0;
}

// 从标准输入读取字符串，直到回车键为止
void readString(char *string, int string_size) {
    int ch;
    int index = 0;

    while ((ch = getchar()) != '\n' && ch != EOF) {
        if (index < string_size - 1) {
            string[index] = (char)ch;  // 确保读入的是char类型
            index++;
        }
    }
    if (ch == '\n') {
        string[index] = '\0';  // 字符串以'\0'结尾
    }
}

// 打印字符串
void printString(char *string) {
    char *pointer_to_string = string;

    printf("The string is: ");
    while (*pointer_to_string != '\0') {
        printf("%c", *pointer_to_string++);
    }
    printf("\n");
}

// 预处理输入字符串，添加'$'和'#'字符
int preprocessString(char *string, char *string_preprocessed) {
    int str_pre_id = 0;
    string_preprocessed[str_pre_id++] = '$';
    string_preprocessed[str_pre_id++] = '#';

    for (int str_id = 0; string[str_id] != '\0'; str_id++) {
        string_preprocessed[str_pre_id++] = string[str_id];
        string_preprocessed[str_pre_id++] = '#';
    }

    string_preprocessed[str_pre_id] = '\0';

    return str_pre_id - 1; // 返回预处理后的字符串长度，最后一位省略
}

// Manacher算法计算最长回文子串
int manacher(char *string, char *result, int str_len) {
    int max_len = 0;

    int longest_pa[MAX_STR_LENGTH];
    int ptr_str = 0, center = 0, Right_pos = 0, ptr_str_inv = 0;

    for (ptr_str = 0; ptr_str <= str_len; ptr_str++) {
        ptr_str_inv = 2 * center - ptr_str;

        if (ptr_str < Right_pos) {
            // 计算当前字符位置的最长回文半径
            longest_pa[ptr_str] = (Right_pos - ptr_str < longest_pa[ptr_str_inv] ? 
                                   Right_pos - ptr_str : longest_pa[ptr_str_inv]);
        } else {
            longest_pa[ptr_str] = 0;
        }

        while (string[ptr_str + longest_pa[ptr_str] + 1] == 
               string[ptr_str - longest_pa[ptr_str] - 1]) {
            longest_pa[ptr_str] += 1;
        }

        if (ptr_str + longest_pa[ptr_str] > Right_pos) {
            center = ptr_str;
            Right_pos = ptr_str + longest_pa[ptr_str];
        }
    }

    int max_len_center_pos = 0;
    for (int id = 0; id <= str_len; id++) {
        if (max_len < longest_pa[id]) {
            max_len = longest_pa[id];
            max_len_center_pos = id;
        }
    }

    if (max_len) {
        int max_len_start_pos = max_len_center_pos - max_len + 1;
        int result_id = 0;
        int string_id = max_len_start_pos;

        for (; result_id < max_len; result_id++) {
            if (string[string_id] != '#' ||
                string[string_id] != '^' || 
                string[string_id] != '$') {
                    result[result_id] = string[string_id];
            }
            string_id += 2;
        }

        result[result_id] = '\0';
    }

    return max_len; // 返回最长回文子串的长度
}
