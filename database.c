#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student
{
int rollnumber;
char name[100];
char phone[100];
float percentage;
struct student *next;
}* head;
void insert(int rollnumber, char* name, char* phone, float percentage)
{
struct student * student=(struct student *) malloc(sizeof(struct student));
student->rollnumber=rollnumber;
strcpy(student->name,name);
strcpy(student->phone,phone);
student->percentage=percentage;
student->next=NULL;
if(head==NULL)
{
head=student;
}
else
{
student->next=head;
head=student;
}
}
void search(int rollnumber)
{
struct student * temp =head;
while(temp!=NULL)
{
if(temp->rollnumber==rollnumber)
{
printf("Roll number: %d",temp->rollnumber);
printf("Name: %s",temp->name);
printf("Phone: %s",temp->phone);
printf("percentage: %0.4f\n",temp->percentage);
return;
}
temp=temp->next;
}
printf("student with roll number %d is not found!!!\n",rollnumber);
}
void update(int rollnumber)
{
struct student * temp=head;
while(temp!=NULL)
{
if(temp->rollnumber==rollnumber)
{
printf("record with roll number %d found !!!\n",rollnumber);
printf("enter new name: ");
scanf("%s",temp->name);
printf("enter new phone number: ");
scanf("%s",temp->phone);
printf("enter new percentage: ");
scanf("%f",temp->percentage);
printf("updation successful!!\n");
return;
}
temp=temp->next;
}
printf("student with rollnumber %d is not found!!\n",rollnumber);
}
void delete(int rollnumber)
{
struct student * temp1 =head;
struct student * temp2 =head;
while(temp1!=NULL)
{
if(temp1->rollnumber==rollnumber){
printf("record with roll number %d found!!!\n",rollnumber);
if(temp1==temp2)
{
head=head->next;
free(temp1);
}
else
{
temp2->next=temp1->next;
free(temp1);
}
printf("record successfully deleted!!\n");
return;
}
temp2=temp1;
temp1=temp1->next;
}
printf("student with roll number %d is not found!!\n", rollnumber);
}
void display()
{
struct student * temp = head;
while(temp!=NULL)
{
printf("Roll number: %d",temp->rollnumber);
printf("Name: %s",temp->name);
printf("Phone: %s",temp->phone);
printf("percentage: %0.4f\n",temp->percentage);
temp=temp->next;
}
}
int main()
{
printf("devina dugar\n");
head=NULL;
int choice;
char name[100];
char phone[100];
int rollnumber;
float percentage;
printf("1 to inserr student details\n 2to search for student details\n 3 student details\n 4 to update student details\n 5 to diaply all students details");
do
{
printf("\n enter choice ");
scanf("%d",&choice);
switch(choice)
{
case 1:
printf("enter roll number: ");
scanf("%d",&rollnumber);
printf("enter name: ");
scanf("%s",&name);
printf("enter phone number: ");
scanf("%s",&phone);
printf("enter percentage: ");
scanf("%f",&percentage);
insert(rollnumber,name,phone,percentage);
break;
case 2:
printf("enter roll number to search: ");
scanf("%d",&rollnumber);
search(rollnumber);
break;
case 3:
printf("enter roll number to delete: ");
scanf("%d",&rollnumber);
delete(rollnumber);
break;
case 4:
printf("enter roll number to update: ");
scanf("%d",&rollnumber);
update(rollnumber);
break;
case 5:
display();
break;
}
}
while(choice!=0);
}
