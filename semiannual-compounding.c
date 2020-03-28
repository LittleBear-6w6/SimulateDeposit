/* 半年複利定期積立金の目標達成期間を算出する*/
#include <stdio.h>

int main(void){
	long int amount, goal, money;
	int period_m, period_y, period_ym;
	float yrate,rate6;
	printf("半年複利定期積立金の目標達成期間を算出します\n");
	printf("毎月の積立額：");
	scanf("%ld" , &amount);
	printf("目標積立額：");
	scanf("%ld" , &goal);
	printf("年利率（％）：");
	scanf("%f" , &yrate);

	if(amount < 0 || goal < 0 || yrate < 0.0){
		printf("毎月の積立額、目標積立額、年利率には正の値を入力してください！\nシミュレーションを終了します。\n");
		return -1;
	}

	period_m = 0;
	period_y = 0;
	rate6 = 1 + (yrate / 100.0) * 0.5;
	money = 0 ;

	while(money < goal){
		period_m++;
		money += amount;
		if( period_m % 6 == 0){
			money = (money - amount * 5) * rate6 + amount * 5 + 0.5;
		}
	}

	period_y = period_m / 12;
	period_ym = period_m % 12;

	printf("目標積立額を達成するために必要な期間は%dヶ月（%d年%dヶ月）となります。\n", period_m , period_y, period_ym);
	printf("総額：%ld円となります。\n" , money);
	return 0;
}
