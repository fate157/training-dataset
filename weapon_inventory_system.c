#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char weapon_name[20];
    int base_dmg;
    int durability;
} Weapon;

Weapon* create_weapon(char* name, int dmg, int dur){
    Weapon* w = (Weapon*)malloc(sizeof(Weapon));
    if (w ==NULL) return NULL;

    strcpy(w->weapon_name, name);
    w->base_dmg = dmg;
    w->durability = dur;

    return w;
}

void attack_monster(Weapon* w) {
    if (w ==NULL) return;
    if (w->durability <=0) {
        printf(">> [%s]은(는) 은 내구도가 0이라 사용할 수 없습니다!\n", w->weapon_name);
        return;
    }
    int current_dmg = w->base_dmg;

    if (strcmp(w->weapon_name,"개 사기 검")==0 && (rand() % 100) < 30) {
        current_dmg = 10000;
        printf("!!! [잭팟] %s 대박 터짐 !!!\n", w->weapon_name);
    }
    printf("[%s] 공격! 데미지 : %d\n", w->weapon_name, current_dmg);

    w->durability--;
    if (w->durability <=0) {
        printf(">>> 펑! [%s]이(가) 파괴되었습니다.\n", w->weapon_name);
    }
}
int main () {
    system("chcp 949 > nul");
    srand(time(NULL));

    int capacity = 5;
    Weapon** inventory = (Weapon**)malloc(sizeof(Weapon*) * capacity);

    inventory[0] = create_weapon("전설의 검", 50, 100);
    inventory[1] = create_weapon("양날의 검", 1000, 1);    // 1번만 쓰면 터짐
    inventory[2] = create_weapon("개 사기 검", 1, 10);    // 도박 아이템
    inventory[3] = create_weapon("보통 검", 10, 50);
    inventory[4] = create_weapon("전설의 총", 1000, 10);


    printf("---전투 시작 ---\n");
    attack_monster(inventory[1]);
    attack_monster(inventory[1]);

    printf("\n --- 도박 테스트 ---\n");
    for (int i = 0; i < 5; i++) attack_monster(inventory[2]);

    for (int i =0; i < capacity; i++) {
        if(inventory[i] != NULL) free(inventory[i]);
    }
    free(inventory);

    return 0;
}
