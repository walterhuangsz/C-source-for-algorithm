/**
 * @file    the_same_number1.c
 * @brief   ...
 * @author  H034115
 * @date    9/28/2012 3:36:15 PM
 */
/*
  http://weibo.com/1915548291/yDjra5ajO#1348465113389
  一个大小为n的数组，里面的数都属于范围[0, n-1]，有不确定的重复元素，
  找到至少一个重复元素，要求O(1)空间和O(n)时间。
 */

#include <stdlib.h>
#include <assert.h>

//swap will not success for value type.
void swap(int x, int y)
{
    int temp;
    temp=x;
    x=y;
    y=temp;
}

//swap will success for refference type
void swap_pointer(int *x, int *y)
{
    int temp; 
    temp = *x;
    *x = *y;
    *y = temp;
}

int find_duplicate(int numberList[] , int n)
{
    int i , j;
    for( i=0;i<n;i++)
    {
        while(numberList[i]!=i)
        {
          if(numberList[i]==numberList[numberList[i]])
          {
             return numberList[i];
          }
          else
          {
             //swap(numberList[i],numberList[numberList[i]]);   This will not swap this two variable.
             swap_pointer(&numberList[i],&numberList[numberList[i]]);
          }
        }
    }
    return -1;
}

int main()
{
    int numberList[]= {3,5,7,4,8,3,5,2,9,1};
    assert(3==find_duplicate(numberList,10));
    return 0;
}
