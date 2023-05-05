#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct monobehaviour
{
    char nome[10];
    int hp;
    int ataq;
    int vel;
    int xp;
    int level;
    int stamina;
    int xpmin;
    int hpmax;
};

int main()
{
    struct monobehaviour player1;
    player1.xp = 0;
    player1.level = 1;
    player1.ataq = 5 + (2 * player1.level);
    player1.hp = 20 + (5 * player1.level);
    player1.stamina = 15 + (4 * player1.level);
    player1.xpmin = 30;
    player1.hpmax = 20 + (5 * player1.level);

    struct monobehaviour slime = {"slime"};
    struct monobehaviour coelho = {"coelho"};
    struct monobehaviour aranha = {"aranha"};  

    printf("Bem vindo bravo guerreiro. Qual o seu nome?\n");
    scanf("%s", player1.nome);
    printf("Olá,%s. Te desejo uma boa sorte nessa aventura.\n", player1.nome);
    while (player1.hp > 0)
    {
        int z = player1.level;
        char escolha;
        char monstername[10];
        int dano, hp, level, xp;
        printf("Você tem: %d de hp", player1.hp);
        printf(". Deseja se curar(c) ou batalhar?(qualquer tecla)\n");
        scanf("%s", &escolha);
        if (escolha == 'c')
        {
            player1.hp += player1.hp / 2;
            if (player1.hp > player1.hpmax)
            {
                player1.hp = player1.hpmax;
            }
            printf("Você esta com %d de hp.\n", player1.hp);
        }
        srand((unsigned)time(NULL));
        int x = rand() % 3;
        switch (x)
        {
        case 0:
            strcpy(monstername, slime.nome);
            level = rand() % z;
            slime.level = level;
            slime.ataq = 4 + (slime.level);
            slime.hp = 25 + (5 * slime.level);
            slime.xp = 10 + (7 * slime.level);
            dano = slime.ataq;
            hp = slime.hp;
            xp = slime.xp;
            break;
        case 1:
            strcpy(monstername, coelho.nome);
            level = rand() % z;
            coelho.level = level;
            coelho.ataq = 4 + (2 * coelho.level);
            coelho.hp = 20 + (5 * coelho.level);
            coelho.xp = 10 + (10 * coelho.level);
            dano = coelho.ataq;
            hp = coelho.hp;
            xp = coelho.xp;
            break;
        case 2:
            strcpy(monstername, aranha.nome);
            level = rand() % z;
            aranha.level = level;
            aranha.ataq = 4 + (3 * aranha.level);
            aranha.hp = 15 + (2 * aranha.level);
            aranha.xp = 10 + (8 * aranha.level);
            dano = aranha.ataq;
            hp = aranha.hp;
            xp = aranha.xp;
            break;

        default:
            break;
        }
        printf("Você encontrou um %s!!\n", monstername);
        printf("Ele tem %d de ataque e %d de vida.\n\n", dano, hp);

        while (hp > 0)
        {
            player1.hp = player1.hp - dano;
            printf("Você foi atacado e está com %d de hp e %d de stamina.\n\n", player1.hp, player1.stamina);
            printf("Ataque basico=%d dano +%d stamina(z)\nAtaque concentrado=%d dano -%d stamina(x)\n\n", player1.ataq, (player1.stamina / 3) + 1, player1.ataq + (player1.stamina / 3), player1.stamina / 2);
            scanf("%s", &escolha);
            switch (escolha)
            {
            case 'x':
                hp = hp - (player1.ataq + (player1.stamina / 3));
                player1.stamina = player1.stamina - player1.stamina / 2;
                break;

            default:
                hp = hp - player1.ataq;
                player1.stamina = player1.stamina + (player1.stamina / 3) + 1;
                break;
            }
            if (hp < 0)
            {
                hp = 0;
            }
            printf("\nEle está com %d de hp\n", hp);
        }
        printf("Você derrotou o monstro e e ganhou %d de xp\n\n", xp);
        player1.xp = player1.xp + xp;
        if (player1.xp > player1.xpmin)
        {
            printf("Você passou de Lv \n+2 ataq\n+5 hp\n+4 stamina\n");
            player1.level++;
            player1.xp = player1.xp - player1.xpmin;
            player1.xpmin = player1.xpmin + player1.xpmin / 10;
        }
    }
    printf("Lamentamos a sua morte Oh bravo guerreiro \n\n");
    return 0;
}
