#include <stdio.h>
int main()
{
  char left[20], right[20];
  int i,type;
  int possibleLeftType, possibleRightType;
  printf("Enter transaction on left:");
  scanf("%s", left);
  printf("Enter transaction on right:");
  scanf("%s", right);

  // check transactions on left
  for (i = 0; left[i] != '\0'; i++)
  {
    if (left[i] >= 97 && left[i] <= 122) //ascii range for small letters
    {
      possibleLeftType = 1;
      break;
    }
    possibleLeftType = 3;
  }

  // check transaction on right
  for (i = 0; right[i+1] != '\0'; i++)
  {
    if (right[i] < right[i + 1]) //if small letter appears after capital letter
    {
      possibleRightType = 2;
      break;
    }
    possibleRightType = 3;
  }

  // consider the innermost type
  possibleLeftType <= possibleRightType ? printf("Type %d\n",possibleLeftType) : printf("Type %d\n",possibleRightType);
}