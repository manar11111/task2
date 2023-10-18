#include <stdio.h>
#include <string.h>
#include <ctype.h>

union Active
{
    struct num
    {
        int type;
        _Bool state;
    } n;
    struct string
    {
        int type;
        char state[6];
    } s;
};

void check_active(union Active active[20], int i, char name[20])
{
    if ((active[i].n.type == 0 && active[i].n.state == 1) || (active[i].s.type == 1 && strcmp(active[i].s.state, "true") == 0))

        printf("\nHello %s to our application you are active \n", name);

    else
        printf("\n your account not active you cannot acces the app \n");
}
void register_active(char state[6], union Active active[20], int *num)
{
    if (strcmp(state, "0") == 0 || strcmp(state, "1") == 0)
    {
        active[*num].n.type = 0;
        active[*num].n.state = atoi(state);
    }
    else
    {
        active[*num].s.type = 1;
        for (int i = 0; state[i]; i++)
        {
            state[i] = tolower(state[i]);
        }
        strcpy(active[*num].s.state, state);
    }
}
int login(char names[20][20], char pass[20][20], union Active active[20])
{
    char name[20];
    printf("\nEnter your username : ");
    scanf("%s", name);

    char password[20];
    printf("\nEnter your password :");
    scanf("%s", password);

    int i = 0;
    while (i < 20)
    {

        if (strcmp(name, names[i]) == 0 && strcmp(password, pass[i]) == 0)
        {

            check_active(active, i, name);

            break;
        }

        i++;
    }
    return i;
}

void Register(char names[20][20], char pass[20][20], union Active active[20], int *num)
{
    char state[6];
    
    printf("\nEnter username :");
    scanf("%s", names[*num]);

    printf("\nEnter password :");
    scanf("%s", pass[*num]);

    printf("\n is the account active? -> True , False , 0 , 1 :");
    scanf("%s", state);

    register_active(state, active, num);

    printf("\nyou regisered successfully\n");
    *num = *num + 1;
}

int main()
{
    char choose[8];
    char names[20][20] = {"manar", "manora"};
    char pass[20][20] = {"123", "456"};
    union Active active[20];
    int num = 2;
    active[0].n.type = 0;
    active[0].n.state = 0;

    active[1].s.type = 1;
    strcpy(active[1].s.state, "true");

again:

    printf("\nDo you want to login or register: ");
    scanf("%s", choose);

    printf("\nHello to %s form \n ", choose);

    if (strcmp(choose, "login") == 0)
    {

        if (login(names, pass, active) == 20)
        {
            printf("\npassword or username is rong\n");

            goto again;
        }
    }

    else if (strcmp(choose, "register") == 0)
    {
        Register(names, pass, active, &num);

        goto again;
    }
    else
    {
        printf("\nchose one option please");
    }

    return 0;
}
