#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

//------------------------------Global declare ------------------------------------
char ownername[100];
int dt, mn, yr;
struct node *backup = NULL, *current = NULL, *temp = NULL, *global_current = NULL, *dog = NULL;
int cat = 1, sadia = 1, bill = 0;

//-------------------function prototype----------------------------
void front_page();
void dashboard();
void check();
void add();
void sellM();
void total_sold();
void customer();
int checkitem(char s[], int val);

//---------------------------------For structure and Node --------------------------
struct node {
    char customer[100];
    int age;
    char customerMedi[100];
    int item;
    char medi[100];
    int qty;
    int taka;
    int bill;
    struct node *next; //linking node
};

//------------------------------------------------create node----------------------------
int i = 1;
struct node* create_node() {
    char s1[20];
    struct node *root;
    root = (struct node *)malloc(sizeof(struct node));

    if(i) {
        printf("Enter following Information to add new medicine \n");
        i = 0;
    }

    printf("\nMedicine Name: ");
    fgets(s1, sizeof(s1), stdin);
    s1[strcspn(s1, "\n")] = '\0'; // Remove the newline character

    strcpy(root->medi, s1);

    printf("Price per pieces(BDT): ");
    int taka;
    scanf("%d", &taka);
    root->taka = taka;

    printf("Medicine Quantity: ");
    int val;
    scanf("%d", &val);
    root->qty = val;

    root->next = NULL;
    return root;
}

//-------------------------------------Main Body-----------------------------------
int main() {
    front_page();
    dashboard();
    return 0;
}

// ----------------------------Front- page ----------------------------------------
void front_page() {
    printf(" \n\n\n\n\n\t\t\t\t\tWelcome Ma'am ");
    printf(" \n\n\t\t\t\t\tPlease enter your name: ");
    fgets(ownername, sizeof(ownername), stdin);
    ownername[strcspn(ownername, "\n")] = '\0'; // Remove the newline character

    printf(" \t\t\t\t\tDate (DD MM YYYY): ");
    scanf("%d %d %d", &dt, &mn, &yr);
    getchar(); // To consume the newline character after date input
}

//-------------------------- Dashboard ------------------------------------
void dashboard() {
    while(1) {
        system("clear"); // Use "clear" instead of "cls" for Unix-based systems
        if(cat == 1) {
            char s[] = "Dashboard of Medistore\n\n\t\t\t\t\t1.Check stored Medicine.\n\t\t\t\t\t2.Add new medicine.\n\t\t\t\t\t3.Sell Medicine.\n\t\t\t\t\t4.Today's selling history.\n\t\t\t\t\t5.End.\n\n\t\t\t\t\tChoose: ";
            printf(" \n\n\t\t\t\t\t");
            for(int i = 0; s[i] != '\0'; i++) {
                printf("%c", s[i]);
                usleep(10000); // Adjust the delay if needed
            }
            cat = 0;
        } else {
            printf(" \n\n\t\t\t\t\t");
            printf("Dashboard of Medistore\n\n\t\t\t\t\t1.Check stored Medicine.\n\t\t\t\t\t2.Add new medicine.\n\t\t\t\t\t3.Sell Medicine.\n\t\t\t\t\t4.Today's selling history.\n\t\t\t\t\t5.End.\n\n\t\t\t\t\tChoose: ");
        }

        int ch;
        scanf("%d", &ch);
        getchar(); // To consume the newline character after choice input

        switch(ch) {
            case 1:
                check();
                break;
            case 2:
                add();
                break;
            case 3:
                sellM();
                break;
            case 4:
                total_sold();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice ...\a");
                break;
        }
    }
}

//--------------------------add medicine----------------------------------------------
void add() {
    i = 1;
    int n;
    system("clear");
    struct node *head = dog;
    current = global_current;

    printf("\n\nHow many Items do you want to insert: ");
    scanf("%d", &n);
    getchar(); // To consume the newline character after number input

    for(int i = 0; i < n; i++) {
        temp = create_node();
        if(head == NULL) {
            head = current = temp;
        } else {
            current->next = temp;
            current = temp;
        }
    }
    if(sadia) {
        backup = head;
        dog = head;
        sadia = 0;
    }

    global_current = current;

    printf("Added successfully ...\a");

    getchar(); // To wait for user input
}

// ---------------------------Traversal ---------------------
void check() {
    system("clear");
    printf("Total stored Medicine are:\n\n\n");
    struct node* ptr = backup;
    if(backup == NULL) {
        printf("Empty...\a");
    } else {
        while(ptr != NULL) {
            size_t len = strcspn(ptr->medi, "\n");
            ptr->medi[len] = '\0';
            if(ptr->qty != 0) {
                printf("Medicine Name: %s, Quantity: %d\n", ptr->medi, ptr->qty);
                printf("\n");
            }
            ptr = ptr->next;
        }
    }
    getchar(); // To wait for user input
}

//----------------------------Sell Medicine ---------------------------------------
void sellM() {
    system("clear");
    if(backup == NULL) {
        printf("Empty store.....\a");
        getchar();
        return;
    } else {
        customer();
    }
}

//----------------------------------------------Linked list for Customer ------------------------------------------
struct node* epo = NULL, *toma, *lamiya;

void customer() {
    char s1[100];
    printf("Enter Medicine Name: ");
    fgets(s1, sizeof(s1), stdin);
    s1[strcspn(s1, "\n")] = '\0'; // Remove the newline character

    printf("Enter Quantity: ");
    int val;
    scanf("%d", &val);
    getchar(); // To consume the newline character after quantity input

    int flop = checkitem(s1, val);
    if(flop == 1) {
        printf("Enter Customer name: ");
        char s2[100];
        fgets(s2, sizeof(s2), stdin);
        s2[strcspn(s2, "\n")] = '\0'; // Remove the newline character

        printf("Enter Customer Age: ");
        int age;
        scanf("%d", &age);
        getchar(); // To consume the newline character after age input

        int amnt = bill;
        printf("\nYour total bill: %d", bill);

        toma = (struct node*)malloc(sizeof(struct node));
        strcpy(toma->customer, s2);
        strcpy(toma->customerMedi, s1);
        toma->bill = amnt;
        toma->item = val;
        toma->age = age;
        toma->next = NULL;

        if(epo == NULL) {
            epo = lamiya = toma;
        } else {
            lamiya->next = toma;
            lamiya = toma;
        }
    } else {
        return;
    }

    getchar(); // To wait for user input
}

//-------------------------------------------------Check Item -------------------------------------------
int checkitem(char s[], int val) {
    struct node *pakistan = backup;
    int k, flag = 0;
    while(pakistan != NULL) {
        k = strcmp(pakistan->medi, s);
        if(k == 0) {
            flag = 1;
            if(val <= pakistan->qty) {
                pakistan->qty -= val;
                bill = val * pakistan->taka;
                return 1;
            } else if(val > pakistan->qty) {
                bill = 0;
                printf("Insufficient according to your demand ..\n\a");
                printf("You demanded %d\n\a", val);
                printf("Stored only %d\n\a", pakistan->qty);
                getchar(); // To wait for user input
                return 0;
            } else if(pakistan->qty == 0) {
                bill = 0;
                printf("Not found 404 !!\a");
                getchar(); // To wait for user input
                return 0;
            }
        }
        pakistan = pakistan->next;
    }
    if(flag == 0) {
        bill = 0;
        printf("Not found 404 !!\a");
        getchar(); // To wait for user input
        return 0;
    }
    return 0;
}

//----------------------------------Total - sold-------------------------------
void total_sold() {
    system("clear");
    printf("Today's selling history: \n\n");
    int sum = 0;
    if(epo == NULL) {
        printf("Sold not yet...\a");
        getchar();
        return;
    } else {
        struct node *p = epo;
        while(p != NULL) {
            printf("\n\nCustomer information ...\n");
            printf("Date: %d/%d/%d\n", dt, mn, yr);
            printf("Name: %s\n", p->customer);
            printf("Age: %d yrs\n", p->age);
            printf("Medicine: %s\n", p->customerMedi);
            printf("Quantity: %d pcs\n", p->item);
            printf("Total bill: %d Tk\n", p->bill);
            sum += p->bill;
            printf("Voucher made by %s\n", ownername);
            p = p->next;
        }
        printf("\n\nToday's total sold: %d Taka.", sum);
    }
    getchar(); // To wait for user input
}
