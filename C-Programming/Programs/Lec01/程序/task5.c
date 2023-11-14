/* Homework : Josephus 问题
 * Author : Brandon Lin 林楠
 * Date : 25 September, 2023 */

#include <stdio.h>

// Declaration
int find_winner ( int player_amounts );

int main(){
  // Definitions (without initialization) 
  int player_amounts; /* 玩家数量 */
  int pre_winner; /* 赢家 */

  // Get the amount of players
  printf("Insert number of players (n): ");
  scanf("%d", &player_amounts);

  // Find the final winner
  pre_winner = find_winner(player_amounts);

  // Print the result
  printf("In the case of %2d players, the winner is %d\n", player_amounts, pre_winner);
  return 0;
}

int
find_winner ( int player_amounts )
{
  // Definitions
  int pre_winner = 0;
  int count;
  const int step = 2;

  // Run the game
  for ( count = step; count <= player_amounts; ++count ) {
    pre_winner = ( pre_winner + step ) % count;
  }

  return pre_winner;
}
