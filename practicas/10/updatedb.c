#include "./student.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
  unsigned index;
  Student myStudent;

  printf("index: ");
  scanf("%d", &index);
  int fd = open(dbName, O_RDONLY, 0);
  int offset = index * sizeof(Student);
  lseek(fd, offset, SEEK_SET);
  read(fd, &myStudent, sizeof(Student));
  close(fd);

  // printf("index %d, id %d, firsName %s, lastName %s, semester %c\n", index,
  //       myStudent.id, myStudent.firstName, myStudent.lastName,
  //       myStudent.semester);

  printf("attribute: ");
  char attributeName[20];
  scanf("%s", attributeName);
  if (strcmp(attributeName, "id") == 0) {
    printf("current id %d, new id: ", myStudent.id);
    scanf("%d", &myStudent.id);
  }
  if (strcmp(attributeName, "firstName") == 0) {
    printf("current firstName %s, new firstName: ", myStudent.firstName);
    scanf("%s", myStudent.firstName);
  }
  if (strcmp(attributeName, "lastName") == 0) {
    printf("current lastName %s, new lastName: ", myStudent.lastName);
    scanf("%s", myStudent.lastName);
  }
  if (strcmp(attributeName, "semester") == 0) {
    printf("current semester %c, new semester: ", myStudent.semester);
    scanf("\n%c", &myStudent.semester);
  }

  fd = open(dbName, O_WRONLY, 0);
  lseek(fd, offset,SEEK_SET);
  write(fd, &myStudent, sizeof(Student));
  close(fd);
  return 0;
}