#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define RESET "\033[0m"

#define RED "\033[31m"

#define GREEN "\033[32m"

#define BLUE "\033[34m"

#define BOLD "\033[1m"

#include <string.h>

void bankStuff();
void initiation();
void debitDetails();
void creditDetails();
void viewDetails();
void closure();
int signUp(char *fullName, char *userName, char *password)
{
    FILE *fp;
    fp = fopen("data.txt", "w");
    printf(BOLD "Full Name:" RESET);
    scanf("%s", fullName);
    printf(BOLD "User Name:" RESET);
    scanf("%s", userName);
    printf(BOLD "Password:" RESET);
    scanf("%s", password);

    fprintf(fp, "FullName: %s UserName: %s Password: %s", fullName, userName, password);
    // ch();
    printf("We are pleased to inform you that, You have successfully Created your Accout.\n");
    // printf("Welcome to Aarzoo Bank %s!\n", userName);
    bankStuff();

    fclose(fp);
}
int signIn(char *userNameIn, char *passwordIn)
{
    FILE *fptr;
    fptr = fopen("data.txt", "r");
    if (fptr == NULL)
    {
        printf("File doesn't Exist.");
        // exit(1);
    }
    char buff[200];
    char a[10];
    char b[10];
    while (((fscanf(fptr, " %*s %*s UserName: %s", a)) == 1))
    {
        while (fscanf(fptr, "%s", b) == 1)
        {
        }
        // printf("%s \n%s", a, b);
    }
    // printf("File Username is: %s",a);
    printf(BOLD "UserName:" RESET);
    scanf("%s", userNameIn);
    printf(BOLD "Password:" RESET);
    scanf("%s", passwordIn);

    if ((strcmp(userNameIn, a)) == 0 && (strcmp(passwordIn, b)) == 0)
    {
        puts("Kudos!! You are an Authorized Person!");
        bankStuff();
    }
    else
    {
        puts("You are not registered yet!! Sorry");
        initiation();
    }
}
void bankStuff()
{

    printf("1. Credit \n2. Debit \n3. View Account \n4. Exit\n");
    int director = 0;
    printf(BOLD RED ">> " RESET);
    scanf("%d", &director);
    if (director == 1)
    {
        FILE *fCredited;
        fCredited = fopen("credited.txt", "a");
        printf(BOLD "Whom Given:" RESET);
        char creditedName[10];
        scanf("%s", creditedName);
        printf(BOLD "How much Given:" RESET);
        char creditedAmount[10];
        scanf("%s", creditedAmount);
        printf(BOLD "Purpose:" RESET);
        char creditedInfo[30];
        scanf("%s", creditedInfo);

        time_t currentTime;
        time(&currentTime);
        char buffer[30];
        strftime(buffer, 30, "%Y-%m-%d~%H:%M:%S", localtime(&currentTime));
        fprintf(fCredited, "%s %25.15s %15.6s %35.35s\n", buffer, creditedName, creditedAmount, creditedInfo);
        printf("\nYour details has been Recorded!!\n");
        closure();
    }
    // printf("Day: %d\n",);

    else if (director == 2)
    {
        FILE *fDebited;
        fDebited = fopen("debited.txt", "a");
        printf(BOLD "Whom Taken:" RESET);
        char debitedName[10];
        scanf("%s", debitedName);
        printf(BOLD "How much Taken:" RESET);
        char debitedAmount[10];
        scanf("%s", debitedAmount);
        char debitedInfo[30];
        printf(BOLD "Purpose:" RESET);
        scanf("%s", debitedInfo);
        time_t currentTime;
        time(&currentTime);
        char buffer[30];
        strftime(buffer, 30, "%Y-%m-%d~%H:%M:%S", localtime(&currentTime));
        fprintf(fDebited, "%s %25.15s %15.6s %35.35s\n",buffer, debitedName, debitedAmount, debitedInfo);

        printf("\nYour details has been Recorded!!\n");
        closure();
    }
    else if (director == 3)
    {
        viewDetails();
    }
    else
    {
        exit(0);
    }
}
void viewDetails()
{
    printf("What you want to View:\n1. Credit Details\n2. Debit Details\n3. Exit\n");

    int director = 0;
    printf(BOLD RED ">> " RESET);
    scanf("%d", &director);
    switch (director)
    {
    case 1:
        creditDetails();
        break;
    case 2:
        debitDetails();
        break;
    case 3:
        exit(0);
        break;
    default:
        break;
    }
}
void closure()
{
    printf("1. Add more Credit/Debit Details\n");
    printf("2. View Details\n");
    printf("3. Exit\n");
    int director = 0;
    printf(BOLD RED ">> " RESET);
    scanf("%d", &director);

    switch (director)
    {
    case 1:
        bankStuff();
        break;
    case 2:
        viewDetails();
        break;
    case 3:
        exit(0);
        break;

    default:
        break;
    }
}
void initiation()
{
    printf(GREEN "****** Welcome to Money Manager *******\n" RESET);
    printf("1. Sign Up\n2. Sign In\n3. Exit\n");
    int director = 0;
    printf(BOLD RED ">> " RESET);
    scanf("%d", &director);

    char fullName[20];
    char userName[8];
    char password[10];

    char userNameIn[8];
    char passwordIn[10];

    switch (director)
    {
    case 1:
        signUp(fullName, userName, password);
        break;
    case 2:
        signIn(userNameIn, passwordIn);
        break;
    case 3:
        exit(0);
        break;

    default:
        break;
    }
}
void creditDetails()
{
    // printf("Function Entered! Credit");
    FILE *creditPtr;
    creditPtr = fopen("credited.txt", "r");
    char buffer[100];
    while ((fscanf(creditPtr, "%s %*s %*s %*s", buffer)) == 1)
    {
        printf("%s\n", buffer);
    }
}
void debitDetails()
{
    FILE *debitPtr;
    debitPtr = fopen("debited.txt", "r");
    char buffer[1000];
    while ((fscanf(debitPtr, "%*s %*s %*s %s", buffer)) == 1)
    {
        printf("%s", buffer);
    }
}

int main()
{
    time_t currentTime;
    time(&currentTime);

    initiation();
    // ch();
}