#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
	int roll;
	char name[30];
	float marks;
	struct student *next;
};

struct student *head = NULL;

void add_student()
{
	struct student *newnode;

	newnode = (struct student *)malloc(sizeof(struct student));

	printf("Enter roll number: ");
	scanf("%d", &newnode->roll);

	printf("Enter name: ");
	scanf("%s", newnode->name);

	printf("Enter marks: ");
	scanf("%f", &newnode->marks);

	newnode->next = NULL;

	if (head == NULL)
	{
		head = newnode;
	}
	else
	{
		struct student *temp = head;

		while (temp->next != NULL)
		{
			temp = temp->next;
		}

		temp->next = newnode;
	}

	printf("Student added successfully!\n");
}

void display()
{
	struct student *temp = head;

	if (head == NULL)
	{
		printf("No student records found.\n");
		return;
	}

	printf("\nStudent Details:\n");

	while (temp != NULL)
	{
		printf("Roll  : %d\n", temp->roll);
		printf("Name  : %s\n", temp->name);
		printf("Marks : %.2f\n", temp->marks);

		temp = temp->next;
	}
}

void search()
{
	int roll;
	struct student *temp = head;

	printf("Enter roll number to search: ");
	scanf("%d", &roll);

	while (temp != NULL)
	{
		if (temp->roll == roll)
		{
			printf("Student Found!\n");
			printf("Roll  : %d\n", temp->roll);
			printf("Name  : %s\n", temp->name);
			printf("Marks : %.2f\n", temp->marks);
			return;
		}

		temp = temp->next;
	}

	printf("Student not found.\n");
}

int main()
{
	int choice;

	while (1)
	{
		printf("\n===== STUDENT MANAGEMENT =====\n");
		printf("1. Add Student\n");
		printf("2. Display Students\n");
		printf("3. Search Student\n");
		printf("4. Exit\n");

		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch (choice)
		{
			case 1:
				add_student();
				break;

			case 2:
				display();
				break;

			case 3:
				search();
				break;

			case 4:
				exit(0);

			default:
				printf("Invalid choice\n");
		}
	}

	return 0;
}


