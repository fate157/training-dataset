#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char weapon_name[20];
	int extra_dmg;
	int durability;
} Weapon;

typedef struct {
	char name[20];
	char tier[15]; 
	int contact
	int power;
	Weapon* equipped_weapon;
} Player;

Weapon* create_weapon(char* name, int dmg, int dur) {
	Weapon* w = (Weapon*)malloc(sizeof(Weapon));

	strcpy(w->weapon_name, name);
	w->extra_dmg = dmg;
	w->durability = dur;

	return w;
}

Player* create_player(char* name, char* tier, int con, int pow) {
	Player* p = (Player*)malloc(sizeof(Player));

	strcpy(p->name, name);
	strcpy(p->tier, tier);
	p->contact = con;
	p->power = pow;
	p->equipped_weapon = NULL;

	return p;
}

int main() {
	Player* p1 = create_player("Otani", "ALL_Stars", 80, 80); 
	Weapon* my_bats = create_weapon("black_bats", 100, 100);

	p1->equipped_weapon = my_bats;

	
	printf("[로그인] %s 선수가 게임에 접속했습니다.\n", p1->name);

	int total_power = p1->power + p1->equipped_weapon->extra_dmg;

	printf("\n--- %s 선수의 상세 정보 ---\n", p1->name);
	printf("등급: %s\n", p1->tier);
	printf("기본 컨택트: %d\n", p1->contact);

	
	printf("최종 파워: %d (기본: %d + 무기추가데미지: %d)\n", total_power, p1->power, p1->equipped_weapon->extra_dmg);

	printf("장착 무기: %s (무기 내구도: %d)\n",
		p1->equipped_weapon->weapon_name,
		p1->equipped_weapon->durability);

	printf("\n[이벤트] 배트를 험하게 써서 부러졌습니다! 장비를 해체합니다.\n");
	p1->equipped_weapon = NULL;

	free(my_bats);
	free(p1);

	return 0;
}