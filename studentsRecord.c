#include<stdio.h>
#include<string.h>
struct Student
{
char name[22];
int rollNumber;
};
void addStudent()
{
char name[21];
int rollNumber;
struct Student g;
char m;
FILE *f;
printf("Student (Add Module)\n");
printf("Enter roll number :");
scanf("%d",&rollNumber);
fflush(stdin);
if(rollNumber<=0)
{
printf("Invalid roll number\n");
return;
}
f=fopen("student.nnn","rb");
if(f!=NULL)
{
while(1)
{
fread(&g,sizeof(struct Student),1,f);
if(feof(f)) break;
if(rollNumber==g.rollNumber)
{
printf("That roll number is alloted to %s\n",g.rollNumber);
fclose(f);
return;
}
}
fclose(f);
}
printf("Enter name of student :");
scanf("%s",name);
fflush(stdin);
printf("Save (Y/N) :");
m=getchar();
fflush(stdin);
if(m!='Y' && m!='y')
{
printf("Student not added\n");
return;
}
g.rollNumber=rollNumber;
strcpy(g.name,name);
f=fopen("student.nnn","ab");
fwrite(&g,sizeof(struct Student),1,f);
fclose(f);
printf("Student added,press enter to continue......");
m=getchar();
fflush(stdin);
}
void editStudent()
{
int found;
char name[21];
int rollNumber;
char m;
FILE *f,*t;
struct Student g,j;
printf("Student (Edit Module)\n");
printf("Enter roll number of student to edit :");
scanf("%d",&rollNumber);
fflush(stdin);
if(rollNumber<=0)
{
printf("Invalid roll number\n");
return;
}
f=fopen("student.nnn","rb");
if(f==NULL) 
{
printf("No students added\n");
return;
}
found=0;
while(1)
{
fread(&g,sizeof(struct Student),1,f);
if(feof(f)) break;
if(g.rollNumber==rollNumber)
{
found=1;
break;
}
}
fclose(f);
if(found==0) 
{
printf("Invalid roll number\n");
return;
}
printf("Name %s\n",g.name);
printf("Edit (Y/N) :");
m=getchar();
fflush(stdin);
if(m!='Y' && m!='y')
{
printf("Not edited\n");
return;
}
printf("Enter new name :");
scanf("%s",name);
fflush(stdin);
printf("Update (Y/N) :");
m=getchar();
fflush(stdin);
if(m!='Y' && m!='y')
{
printf("Not updated\n");
return;
}
strcpy(g.name,name);
f=fopen("student.nnn","rb");
t=fopen("fhaltu.nnn","wb");
while(1)
{
fread(&j,sizeof(struct Student),1,f);
if(feof(f)) break;
if(g.rollNumber!=j.rollNumber)
{
fwrite(&j,sizeof(struct Student),1,t);
}
else
{
fwrite(&g,sizeof(struct Student),1,t);
}
}
fclose(f);
fclose(t);
f=fopen("student.nnn","wb");
t=fopen("fhaltu.nnn","rb");
while(1)
{
fread(&j,sizeof(struct Student),1,t);
if(feof(t)) break;
fwrite(&j,sizeof(struct Student),1,f);
}
fclose(t);
fclose(f);
t=fopen("fhaltu.nnn","wb");
fclose(t);
printf("Student updated,press enter to continue......");
m=getchar();
fflush(stdin);
}
void deleteStudent()
{
char m;
int found;
int rollNumber;
struct Student g,j;
FILE *f,*t;
printf("Student (Delete Module)\n");
printf("Enter roll number of student to delete :");
scanf("%d",&rollNumber);
fflush(stdin);
if(rollNumber<=0)
{
printf("Invalid roll number\n");
return;
}
f=fopen("student.nnn","rb");
if(f==NULL)
{
printf("Invalid roll number\n");
return;
}
found=0;
while(1)
{
fread(&g,sizeof(struct Student),1,f);
if(feof(f)) break;
if(rollNumber==g.rollNumber)
{
found=1;
break;
}
}
fclose(f);
if(found==0)
{
printf("Invalid roll number\n");
return;
}
printf("Name %s\n",g.name);
printf("Delete (Y/N):");
m=getchar();
fflush(stdin);
if(m!='Y' && m!='y')
{
printf("Student not deleted\n");
return;
}
f=fopen("student.nnn","rb");
t=fopen("fhaltu.nnn","wb");
while(1)
{
fread(&j,sizeof(struct Student),1,f);
if(feof(f)) break;
if(g.rollNumber!=j.rollNumber)
{
fwrite(&j,sizeof(struct Student),1,t);
}
}
fclose(f);
fclose(t);
t=fopen("fhaltu.nnn","rb");
f=fopen("student.nnn","wb");
while(1)
{
fread(&j,sizeof(struct Student),1,t);
if(feof(t)) break;
fwrite(&j,sizeof(struct Student),1,f);
}
fclose(t);
fclose(f);
t=fopen("fhaltu.nnn","wb");
fclose(t);
printf("Student deleted,press enter to continue.........");
m=getchar();
fflush(stdin);
}
void searchStudent()
{
char m;
int rollNumber,found;
struct Student g;
FILE *f;
printf("Enter roll number to search student :");
scanf("%d",&rollNumber);
fflush(stdin);
if(rollNumber<=0)
{
printf("Invalid roll number\n");
return;
}
f=fopen("student.nnn","rb");
if(f==NULL) 
{
printf("Invalid roll number\n");
return;
}
found=0;
while(1)
{
fread(&g,sizeof(struct Student),1,f);
if(feof(f)) break;
if(rollNumber==g.rollNumber)
{
found=1;
break;
}
}
fclose(f);
if(found==0)
{
printf("Invalid roll number\n");
return;
}
printf("Name %s\n",g.name);
printf("Press enter to continue...........");
m=getchar();
fflush(stdin);
}
void displayListOfStudents()
{
int x;
char m;
struct Student s;
FILE *k;
printf("Student (List Module)\n");
k=fopen("student.nnn","rb");
if(k==NULL) 
{
printf("No students is added\n");
return;
}
x=0;
while(1)
{
fread(&s,sizeof(struct Student),1,k);
if(feof(k)) break;
x++;
printf("Name :%s\n",s.name);
printf("(%d) Roll number :%d\n",x,s.rollNumber);
}
fclose(k);
if(x==0)
{
printf("No students added,press enter to continue.....");
}
else
{
printf("Press enter to continue.........");
}
m=getchar();
fflush(stdin);
}
int main()
{
int ch;
while(1)
{
printf("1.Add students\n");
printf("2.Display list of students\n");
printf("3.Edit student\n");
printf("4.Search student\n");
printf("5.Delete student\n");
printf("6.Exit\n");
printf("Enter your choice :");
scanf("%d",&ch);
fflush(stdin);
if(ch==1) addStudent();
if(ch==2) displayListOfStudents();
if(ch==3) editStudent();
if(ch==4) searchStudent();
if(ch==5) deleteStudent();
if(ch==6) break;
}
return 0;
}