#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{

    char *set[100];
    int Val;
    struct node *next;
    int sizearr;

} node;

int strcmpa(char *s1, char *s2)
{

    while (*s1 && tolower(*s1) == tolower(*s2))
    {
        s1++;
        s2++;
    }
    return tolower(*s1) - tolower(*s2);
}

void sorter(char **str)
{
}

void print(node *head, int num)
{
}

void addNode(node *head, char *word, int num)
{
    node *temp = head;
    int v;

    while (temp != NULL)
    {
        v = temp->sizearr;
        if (temp->Val == num)
        {

            strcpy(temp->set[v], word);

            temp->sizearr += 1;
        }
        temp = temp->next;
    }
    /* This has created the list and is consitantly adding to it   */
}

void clear(node *head, int num)
{

    int v;
    node *temp = head;
    temp->sizearr = 0;

    while (temp != NULL)
    {
        v = temp->sizearr;
        if (temp->Val == num)
        {

            strcpy(temp->set[v], " ");

            temp->sizearr -= 1;
        }
        temp = temp->next;
    }
}

void printSets(node *head)
{

    int i;
    while (head != NULL)
    {

        for (i = 0; i < head->sizearr; i++)
        {

            if (head->set[i] != NULL)
            {
                printf("%s", head->set[i]);
            }
            else
                continue;
        }

        head = head->next;
    }
    printf("\n");
}

void copy(int to, int from, node *head)
{
    node *temp = head;
    int v;
    node *forval = temp;
    int k;

    while (temp != NULL)
    {
        v = temp->sizearr;
        if (temp->Val == from)
            forval->Val = temp->Val;

        if (temp->Val == to)
        {

            strcpy(temp->set[v], forval->set[v]);

            temp->sizearr += 1;
        }
        temp = temp->next;
    }
}

void removeNode(int num, node *head, char *input)
{
    int vin = 0;
    int i;
    while (head != NULL)
    {

        if (head->Val == num)
        {

            for (i = 0; i < head->sizearr; i++)
            {
                /* fix here */

                vin = strcmp(input, head->set[i]);
                if (vin == 0)
                {

                    strcpy(head->set[i], NULL);
                }
            }
        }

        head = head->next;
    }
}
void unionSets(int num, int num1, int num2, node *head)
{

    node *temp = head;
    int v;
    node *forval = temp;
    int k;

    while (temp != NULL)
    {
        v = temp->sizearr;
        if (temp->Val == num)
            forval->Val = temp->Val;

        if (temp->Val == 0)
        {

            strcpy(temp->set[v], forval->set[v]);

            temp->sizearr += 1;
        }
        temp = temp->next;
    }
}

void intersection()
{



}
void symmetricdifference(int num, int num1, int num2, node *head)
{
    node *temp = head;
    int v;
    node *forval = temp;
    int k;

    while (temp != NULL)
    {
        v = temp->sizearr;
        if (temp->Val == num)
            forval->Val = temp->Val;

        if (temp->Val == 0)
        {

            strcpy(temp->set[v], forval->set[v]);

            temp->sizearr += 1;
        }
        temp = temp->next;
    }
}

void printit()
{
    printf("***** Menu Options *****\nAdd String: a or A\nRemove String: r or R\nUnion: u or U\nIntersection: i or I\nSymmetric Difference: s or S\nCopy: c or C\nClear: z or Z\nPrint Set: p\nPrint All Sets: P\nQuit: q or Q\n");
}

void create(int size, node *head)
{

    int i, j;
    node *temp = head;

    if (size == 1)
    {
        return;
    }
    else
    {
        for (i = 1; i < size; i++)
        {

            node *new = malloc(sizeof(node));

            for (j = 0; j < 100; j++)
            {
                temp->set[j] = malloc(sizeof(char) * 100);
            }

            new->Val = i;

            temp->next = new;
            new->next = NULL;
            temp = new;
        }
    }
}

int main()
{

    char kin[100], word[100];
    char c;
    int listSize, i, num, num1, num2, vin = 0;
    node *head = (node *)malloc(sizeof(node));
    node *lin = NULL;

    printf("Enter Number of Sets to be created: ");
    fgets(kin, 100, stdin);
    sscanf(kin, "%d", &listSize);

    head->Val = 0;
    head->next = NULL;
    head->sizearr = 0;

    create(listSize, head); /* creates the link of structs */

    /* for printing the menu */
    printit();
    fgets(kin, 100, stdin);
    sscanf(kin, "%c", &c);

    while (c != 'q' || c != 'Q')
    {

        switch (c)
        {

        case 'a':
        case 'A':
            printf("Enter Set to add to: ");
            fgets(kin, 100, stdin);
            sscanf(kin, "%d", &num);
            while (num > listSize || num < 0)
            {
                printf("Not valid set re-enter: ");
                fgets(kin, 100, stdin);
                sscanf(kin, "%d", &num);
            }
            printf("Enter string to add to: ");
            fgets(kin, 100, stdin);
            sscanf(kin, "%[^ ]", word);

            addNode(head, word, num);

            /* call functino */
            break;

        case 'r':
        case 'R':
            printf("Enter Set to remove from: ");
            fgets(kin, 100, stdin);
            sscanf(kin, "%d", &num);
            while (num > listSize)
            {
                printf("Not valid set re-enter: ");
                fgets(kin, 100, stdin);
                sscanf(kin, "%d", &num);
            }
            printf("Enter Set to remove from: ");
            fgets(kin, 100, stdin);
            sscanf(kin, "%[^ ]", word);

            removeNode(num, head, word);
            /* call functino */
            break;

        case 'u':
        case 'U':

            printf("Enter destination set: ");
            fgets(kin, 100, stdin);
            sscanf(kin, "%d", &num);
            while (num > listSize)
            {
                printf("Not valid set re-enter: ");
                fgets(kin, 100, stdin);
                sscanf(kin, "%d", &num);
            }
            printf("Enter 1st set to union from: ");
            fgets(kin, 100, stdin);
            sscanf(kin, "%d", &num1);
            while (num > listSize)
            {
                printf("Not valid set re-enter: ");
                fgets(kin, 100, stdin);
                sscanf(kin, "%d", &num1);
            }
            printf("Enter 2nd set to union from: ");
            fgets(kin, 100, stdin);
            sscanf(kin, "%d", &num2);
            while (num > listSize)
            {
                printf("Not valid set re-enter: ");
                fgets(kin, 100, stdin);
                sscanf(kin, "%d", &num2);
            }
                unionSets(num,num1,num2,head);
            /* call functino */
            break;

        case 'i':
        case 'I':
            printf("Enter destination set: ");
            fgets(kin, 100, stdin);
            sscanf(kin, "%d", &num);
            while (num > listSize)
            {
                printf("Not valid set re-enter: ");
                fgets(kin, 100, stdin);
                sscanf(kin, "%d", &num);
            }
            printf("Enter 1st set to intersect from: ");
            fgets(kin, 100, stdin);
            sscanf(kin, "%d", &num1);
            while (num > listSize)
            {
                printf("Not valid set re-enter: ");
                fgets(kin, 100, stdin);
                sscanf(kin, "%d", &num1);
            }
            printf("Enter 2nd set to intersect from: ");
            fgets(kin, 100, stdin);
            sscanf(kin, "%d", &num2);
            while (num > listSize)
            {
                printf("Not valid set re-enter: ");
                fgets(kin, 100, stdin);
                sscanf(kin, "%d", &num2);
            }

            intersection();
            /* call functino */
            break;

        case 's':
        case 'S':
            printf("Enter destination set: ");
            fgets(kin, 100, stdin);
            sscanf(kin, "%d", &num);
            while (num > listSize)
            {
                printf("Not valid set re-enter: ");
                fgets(kin, 100, stdin);
                sscanf(kin, "%d", &num);
            }
            printf("Enter 1st set to symmetric difference from: ");
            fgets(kin, 100, stdin);
            sscanf(kin, "%d", &num1);
            while (num > listSize)
            {
                printf("Not valid set re-enter: ");
                fgets(kin, 100, stdin);
                sscanf(kin, "%d", &num1);
            }
            printf("Enter 2nd set to symmetric difference from: ");
            fgets(kin, 100, stdin);
            sscanf(kin, "%d", &num2);
            while (num > listSize)
            {
                printf("Not valid set re-enter: ");
                fgets(kin, 100, stdin);
                sscanf(kin, "%d", &num2);
            }
            symmetricdifference(num,num1,num2,head);
            /* call functino */
            break;

        case 'c':
        case 'C':
            printf("Enter set to copy to: ");
            fgets(kin, 100, stdin);
            sscanf(kin, "%d", &num);
            while (num > listSize)
            {
                printf("Not valid set re-enter: ");
                fgets(kin, 100, stdin);
                sscanf(kin, "%d", &num);
            }
            printf("Enter set to copy from: ");
            fgets(kin, 100, stdin);
            sscanf(kin, "%d", &num1);
            while (num > listSize)
            {
                printf("Not valid set re-enter: ");
                fgets(kin, 100, stdin);
                sscanf(kin, "%d", &num1);
            }

            copy(num, num1, head);
            /* call functino */
            break;
        case 'z':
        case 'Z':
            printf("Enter set to clear: ");
            fgets(kin, 100, stdin);
            sscanf(kin, "%d", &num);
            while (num > listSize)
            {
                printf("Not valid set re-enter: ");
                fgets(kin, 100, stdin);
                sscanf(kin, "%d", &num);
            }

            clear(head, num);

            /* call functino */
            break;
        case 'q':
        case 'Q':
            exit(0);
            break;

        case 'P':

            printSets(head);
            /* call functino */
            break;

        case 'p':
            printf("Enter set to print: ");
            fgets(kin, 100, stdin);
            sscanf(kin, "%d", &num);
            while (num > listSize)
            {
                printf("Not valid set re-enter: ");
                fgets(kin, 100, stdin);
                sscanf(kin, "%d", &num);
            }
                print(head,num);
            /* call functino */
            break;
        default:
            printf("\nInvalid Input\n\n");
        }

        printit();
        fgets(kin, 100, stdin);
        sscanf(kin, "%c", &c);
    }

    return 0;
}
