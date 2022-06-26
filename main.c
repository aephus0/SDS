#include "main.h"
#include <stdio.h>

int saveStudent();
struct Student {
  char name[20];
  char age[3];
  char address[20];
  char phone[20];
  char email[20];
  char course[20];
  char roll[20];
  char semester[20];
  char year[20];
  uint32_t id;
};

struct Student student;

char input[2];

int printMenu() {
  system("clear");
  printf("\n");
  printf("1. Add Student\n");
  printf("2. Delete Student\n");
  printf("3. Update Student\n");
  printf("4. Search Student\n");
  printf("5. Print Student\n");
  printf("6. Exit\n");
  printf("\n");
  printf("Enter your choice: ");
  getInput(input, 2);
  printf("%c\n", input[0]);
  return 0;
}

void printStudent(struct Student *student) {
  system("clear");
  printf("\n");
  printf("Name: %s\n", student->name);
  printf("Age: %s\n", student->age);
  printf("Address: %s\n", student->address);
  printf("Phone: %s\n", student->phone);
  printf("Email: %s\n", student->email);
  printf("Course: %s\n", student->course);
  printf("Roll: %s\n", student->roll);
  printf("Semester: %s\n", student->semester);
  printf("Year: %s\n", student->year);
  printf("ID: %d\n", student->id);
  printf("\n");
  printf("Press any key to continue...");
  getchar();
}

struct Student *addStudent() {
  printf("Enter Student Name: ");
  getInput(student.name, 20);
  printf("Enter Student Age: ");
  getInput(student.age, 3);
  printf("Enter Student Address: ");
  getInput(student.address, 20);
  printf("Enter Student Phone: ");
  getInput(student.phone, 20);
  printf("Enter Student Email: ");
  getInput(student.email, 20);
  printf("Enter Student Course: ");
  getInput(student.course, 20);
  printf("Enter Student Roll: ");
  getInput(student.roll, 20);
  printf("Enter Student Semester: ");
  getInput(student.semester, 20);
  printf("Enter Student Year: ");
  getInput(student.year, 20);
  student.id = rand() % 100;
  saveStudent(&student);
  return &student;
}
int deleteStudent() { return 0; };
int updateStudent() {
  printf("Enter Student Name: ");
  getInput(student.name, 20);
  return 0;
};
int searchStudent() { return 0; };

void makeSelection(char *buf) {
  switch (buf[0]) {
  case '1':
    addStudent();
    break;
  case '2':
    deleteStudent();
    break;
  case '3':
    updateStudent();
    break;
  case '4':
    searchStudent();
    break;
  case '5':
    printStudent(&student);
    break;
  case '6':
    exit(0);
    break;
  default:
    printf("Invalid input\n");
    break;
  }
}

int saveStudent(struct Student *student) {
  FILE *fp;
  fp = fopen("student.bin", "ab");
  if (fp == NULL) {
    printf("Error opening file\n");
    return 1;
  }
  fwrite(&student, sizeof(struct Student), 1, fp);
  fclose(fp);
  return 0;
}

int initialize() {
  int *buf;
  buf = (int *)malloc(256);
  printf("%d\n", *buf);
  getchar();
  FILE *fp;
  fp = fopen("student.bin", "rb");
  if (fp == NULL) {
    printf("Error opening file\n");
  } else {
    fread(&buf, sizeof(buf), 1, fp);
    fclose(fp);
  }
  fp = fopen("student.bin", "wb");
  *buf = 1;
  fwrite(&buf, sizeof(buf), 1, fp);
  fclose(fp);
  free(buf);
  return 0;
}

int main(int argc, char **argv) {
  while (1) {
    initialize();
    printMenu();
    makeSelection(input);
  }
  return 0;
}