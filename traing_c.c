#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char weapon_name[20];
	int extra_dmg;
	int durability;
} Weapon;

Weapon* create_weapon(char* name, int dmg, int dur) {
	Weapon* w = (Weapon*)malloc(sizeof(Weapon));

	strcpy(w->weapon_name, name);
	w->extra_dmg = dmg;
	w->durability = dur;
	return w;
}

int main() {
	system("chcp 949 > nul");

	int capacity = 3;

	Weapon** inventory = (Weapon**)malloc(sizeof(Weapon*) * capacity);

	inventory[0] = create_weapon("전설의 검", 50,100);
	inventory[1]= create_weapon("독 묻은 단검", 30, 100);
	inventory[2] = create_weapon("나무 막대기", 5, 100); 


	printf("--- 현재 인벤토리 ---\n");
	for (int i = 0; i < capacity; i++) {
		if (inventory[i] != NULL) {
			printf("[%d번 슬롯] %s (공격력 : %d)\n", i, inventory[i]->weapon_name, inventory[i]->extra_dmg);

		}

	}

	printf("\n--- 검과 단검의 위치를 바꿉니다 ---\n");
	Weapon* temp = inventory[0];
	inventory[0] = inventory[1];
	inventory[1] = temp;

	for (int i = 0; i < capacity; i++) {
		printf("[%d번 슬롯] %s\n" ,i, inventory[i]->weapon_name);

	}

	for (int i = 0; i < capacity; i++) free(inventory[i]);
	free(inventory);

	return 0;
}
