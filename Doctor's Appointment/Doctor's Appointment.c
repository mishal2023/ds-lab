#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int serial;
    char name[100];
    char phone[12];
    struct node *next;
};
typedef struct node node;

int appointment = 20;
node *head;

void Appoint(node *pointer)
{
    printf("                      *********Appointment Portal*********\n");
    int serial;
    char key;
    if (appointment == 0)
    {
        printf("Sorry! Today's Appointment Full. Try after 8 p.m. for tomorrow's appointment\n\n\n");
        printf("Press any key to continue...");
        getchar();
        return;
    }
    else
    {
        if (pointer == NULL)
        {
            head = (node *)malloc(sizeof(node));
            pointer = head;
            pointer->next = NULL;
            printf("Enter your name: ");
            getchar();
            fgets(pointer->name, sizeof(pointer->name), stdin);

        phone_tag1:
            printf("Enter Mobile Number: ");
            fgets(pointer->phone, sizeof(pointer->phone), stdin);
            int len = strlen(pointer->phone);
            if (len != 11)
            {
                printf("Invalid Mobile Number. Try again\n");
                goto phone_tag1;
            }
            for (int i = 0; pointer->phone[i] != '\0'; i++)
            {
                if (pointer->phone[i] < '0' || pointer->phone[i] > '9')
                {
                    printf("Invalid Mobile Number. Try again\n");
                    goto phone_tag1;
                }
            }
            appointment--;
            serial = 20 - appointment;
            pointer->serial = serial;
            printf("\n\nAppointment accepted.\n");
            printf("Your serial number is %d.\n\n\n", pointer->serial);
            printf("Press any key to continue...");
            scanf("%c", &key);
            getchar(); // consume the newline character left in the input buffer
            return;
        }
        while (pointer->next != NULL)
        {
            pointer = pointer->next;
        }

        pointer->next = (node *)malloc(sizeof(node));
        pointer = pointer->next;
        pointer->next = NULL;
        printf("Enter your name: ");
        getchar();
        fgets(pointer->name, sizeof(pointer->name), stdin);

    phone_tag:
        printf("Enter your Mobile Number: ");
        fgets(pointer->phone, sizeof(pointer->phone), stdin);
        int len = strlen(pointer->phone);
        if (len != 12)
        {
            printf("Invalid Mobile Number. Try again\n");
            goto phone_tag;
        }
        for (int i = 0; pointer->phone[i] != '\0'; i++)
        {
            if (pointer->phone[i] < '0' || pointer->phone[i] > '9')
            {
                printf("Invalid Mobile Number. Try again\n");
                goto phone_tag;
            }
        }
        appointment--;
        serial = 20 - appointment;
        pointer->serial = serial;
        printf("\n\nAppointment accepted.\n");
        printf("Your serial number is %d.\n\n\n", pointer->serial);
        printf("Press any key to continue...");
        scanf("%c", &key);
        getchar(); // consume the newline character left in the input buffer
        return;
    }
}

void Showlist(node *pointer)
{
    printf("                       *********Today's appointment list*********\n");
    if (pointer == NULL)
    {
        printf("No Appointment today!!!\n\n\n");
    }
    while (pointer != NULL)
    {
        printf("%d: ", pointer->serial);
        printf("%s (Ph: %s )\n", pointer->name, pointer->phone);
        pointer = pointer->next;
    }
    printf("\n\n\n\nPress enter to go back to Doctor's menu: ");
    getchar();
    getchar(); // consume the newline character left in the input buffer
    system("cls"); // clear screen
}

void Call(node **head)
{
    node *temp;
    temp = *head;
    char key;
    if (temp == NULL)
    {
        printf("No Appointment today!!!\n\n\n");
        printf("Press enter to go back to the main menu");
        getchar();
        getchar(); // consume the newline character left in the input buffer
        system("cls"); // clear screen
        return;
    }
    printf("Calling:\n");
    printf("Serial %d: %s\nPhone:%s\n\n", temp->serial, temp->name, temp->phone);
    if (temp->next != NULL)
    {
        temp = temp->next;
        printf("Next is:\n");
        printf("Serial %d: %s\nPhone:%s\n\n", temp->serial, temp->name, temp->phone);
    }
    printf("\nPress enter to go back to Doctor's Menu...");
    getchar();
    getchar(); // consume the newline character left in the input buffer

    *head = (*head)->next;
    free(temp);
    system("cls"); // clear screen
    return;
}

int main()
{
    head = NULL;
    char query, query2;
    while (1)
    {
        printf("                      *********Main Menu*********\n");
    main_again:
        printf("1. I'm a Patient\n2. I'm the Doctor\n3. Exit\n\n\n");
        scanf(" %c", &query);
        getchar(); // consume the newline character left in the input buffer
        if (query == '1')
        {
            while (1)
            {
                system("cls"); // clear screen
                printf("                      *********Patient's Menu*********\n");
                printf("1. Place Appointment\n2. Back to main menu.\n\n");
                char appoint1;
            patient_again:
                scanf(" %c", &appoint1);
                getchar(); // consume the newline character left in the input buffer
                if (appoint1 == '1')
                {
                    system("cls"); // clear screen
                    Appoint(head);
                }
                else if (appoint1 == '2')
                {
                    system("cls"); // clear screen
                    break;
                }
                else
                {
                    printf("Wrong Command!!!\n\n");
                    goto patient_again;
                }
            }
        }
        else if (query == '2')
        {
            while (1)
            {
                system("cls"); // clear screen
                printf("                      *********Doctor's Menu*********\n");
                printf("1. Show list\n2. Call next\n3. Back to main menu.\n\n\n");
                scanf(" %c", &query2);
                getchar(); // consume the newline character left in the input buffer
                if (query2 == '1')
                {
                    system("cls"); // clear screen
                    Showlist(head);
                }
                else if (query2 == '2')
                {
                    system("cls"); // clear screen
                    Call(&head);
                }
                else if (query2 == '3')
                {
                    system("cls"); // clear screen
                    break;
                }
                else
                {
                    printf("Wrong Command!!!\n\n");
                    continue;
                }
            }
        }
        else if (query == '3')
        {
            break; // Exit the program
        }
        else
        {
            printf("Wrong Command!!!\n\n");
            goto main_again;
        }
    }
    return 0;
}

