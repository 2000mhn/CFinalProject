#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int iteration=3;
struct node{
char issue[200];
char decision1[200];
int people_decision1;
int darbar_decision1;
int khazaneh_decision1;
char decision2[200];
int people_decision2;
int darbar_decision2;
int khazaneh_decision2;
int iteration;
struct node* next;
};
struct node *create_node(char issue[200], char decision1[200], int people_decision1, int darbar_decision1, int khazaneh_decision1,char decision2[200], int people_decision2, int darbar_decision2, int khazaneh_decision2)
{
struct node *nn;
nn=(struct node*)malloc(sizeof(struct node));
strcpy(issue, nn->issue);
strcpy(decision1, nn->decision1);
nn->people_decision1=people_decision1;
nn->darbar_decision1=darbar_decision1;
nn->khazaneh_decision1=khazaneh_decision1;
strcpy(decision2, nn->decision2);
nn->people_decision2=people_decision2;
nn->darbar_decision2=darbar_decision2;
nn->khazaneh_decision2=khazaneh_decision2;
nn->next=NULL;
return nn;

}
struct node *My_list(struct node **list, int number)
{
FILE *fp;
int tmp=number;
char buf[100], issue[200], decision1[200], decision2[200];
int p_d1, d_d1, k_d1, p_d2, d_d2, k_d2;
int static counter=1;
snprintf(buf, sizeof(buf), "c%d.txt", counter);
counter++;
fp=fopen(buf, "r");
fgets(issue, 201, fp);
fgets(decision1, 201, fp);
fscanf(fp, "%d", &p_d1);
fscanf(fp, "%d", &d_d1);
fscanf(fp, "%d", &k_d1);
fgets(decision2, 201, fp);
fscanf(fp, "%d", &p_d2);
fscanf(fp, "%d", &d_d2);
fscanf(fp, "%d", &k_d2);
fclose(fp);
*list=create_node(issue, decision1,p_d1, d_d1, k_d1, decision2, p_d2, d_d2, k_d2);
int static count=0;
count++;
if(count==tmp)
    return 0;
    else

return My_list(&((*list)->next), number);
}

void My_empire(void)
{
char *name_emperor;
name_emperor=(char*)malloc(50*sizeof(char));
scanf("%s", name_emperor);

}


void Body_Game(struct node **list,int number)
{
int choice;
int counter=0;
struct node *current;
srand(time(NULL));
choice=rand()%number;
for(current=*list;counter!=(choice-1);current=current->next)  /*(choice-1):this is due to access to the right element of linked list.*/
{
    counter++;
}

return Body_Game(list, number);

}

int main()
{
FILE *fp;
int i=0, counter=0;
char**filename;
char buf[10];
struct node *list;
fp=fopen("CHOICES.txt", "r");
if(fp==NULL)
    return 0;
while(fgets(buf, 8, fp)!=NULL)
counter++;
close(fp);
My_list(&list, counter);
My_empire();
//Body_Game(&list, counter);
}

