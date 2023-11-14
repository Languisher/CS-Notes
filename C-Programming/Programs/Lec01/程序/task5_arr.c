/* Homework : Josephus 问题
 * Author : Brandon Lin 林楠
 * Date : 25 September, 2023 */

#include <stdio.h>

// Declaration
int find_winner(int player_amounts);

int main() {
    int player_amounts;
    int pre_winner;

    // 获取玩家数量
    printf("Insert number of players (n): ");
    scanf("%d", &player_amounts);

    // 找到最终赢家
    pre_winner = find_winner(player_amounts);

    // 打印最终结果
    printf("In the case of %2d players, the winner is %d\n", player_amounts, pre_winner);
    return 0;
}

int find_winner(int player_amounts) {
    // 创建玩家列表
    int player_arr[player_amounts];
    int exist_players = player_amounts;
    for (int i = 0; i < player_amounts; i++) {
        player_arr[i] = i;
    }

    int current_player_index = -1; // 一定一定要从 -1 开始！！！！！！血的教训啊啊啊啊啊

    // 运行游戏
    while (exist_players > 1) {
        // 寻找下一个活着的玩家
        int count = 0;
        while (count < 2) {
            current_player_index = (current_player_index + 1) % player_amounts;
            if (player_arr[current_player_index] != -1) {
                count++;
            }
        }

        printf("current_player_index %d.\n", current_player_index);
        // 淘汰当前玩家
        player_arr[current_player_index] = -1;
        exist_players--;

    }

    // 返回赢家的编号
    for (int i = 0; i < player_amounts; i++) {
        if (player_arr[i] != -1) {
            return player_arr[i];
        }
    }

    return 0; // 只是不让编译器爆出警告……
}
