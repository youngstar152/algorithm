#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100000

void bubblesort(int data[], int n);
void insertsort( int data[], int n );
void quicksort(int data[], int first, int last);
void selectsort( int data[], int n );
clock_t clock(void);

int main(){
  int i, a[MAX];
  clock_t startTime, endTime, totalTime;

  srand(2);

  for( i = 0 ; i < MAX ; i++ ){
    a[i] = rand() %MAX;
    //printf("%d",a[i]);
  }
    

  startTime = clock() ;
  //bubblesort( a, MAX ); 
  //insertsort( a, MAX); 
  //quicksort( a, 0, MAX-1 );
  //selectsort(a,MAX);
  comb_sort(a,MAX);
  endTime = clock() ;

  totalTime = endTime - startTime;
  //for( i = 0 ; i < MAX ; i++ ){
    //printf("%d\n",a[i]);}
  //printf("bubblesort:totalTime = %d[ms]\n",totalTime);
  //printf("insertsort:totalTime = %d[ms]\n",totalTime);
  //printf("quicksort:totalTime = %d[ms]\n",totalTime);
  //printf("selectsort:totalTime = %d[ms]\n",totalTime);
  printf("com_sort:totalTime = %d[ms]\n",totalTime);

  return 0;
}

void bubblesort(int data[], int n)
{
  int i, j, t, sw = 1;
  for( i = 1 ; sw && i < n ; i++ ){
    sw = 0;
    for( j = n - 1 ; j >= i ; j-- ){
      if( data[j-1] > data[j] ){
	t = data[j-1];
	data[j-1] = data[j];
	data[j] = t;
	sw = 1;
      }
    }
  }
  return;
}

void insertsort( int data[], int n )
{
  int i, j, k, t;

  for( i=1 ; i < n ; i++ ){
    for( j=i-1 ; j >= 0 ; j-- ){
      if( data[j+1] < data[j] ){
	t = data[j+1];
	data[j+1] = data[j];
	data[j] = t;
      }else{
	break;
      }
    }
  }
  return;
}

void quicksort(int data[], int first, int last)
{
  int i, j, x, t;
  x = data[(first+last)/2];
  i = first;
  j = last;
  while(1){
    while( data[i] < x ) i++;
    while( x < data[j] ) j--;
    if( i >= j ) break;
    t = data[i]; 
    data[i] = data[j]; 
    data[j] = t;
    i++;
    j--;
  }
  if( first < i-1 )
    quicksort(data,first,i-1); 
  if( j+1 < last )
    quicksort(data,j+1,last);
}

void selectsort (int data[],int n)
{
  int i,j,k,min;
  for(i=0;i<n-1;i++){
    k = i;
    for(j=i+1;j<n;j++){
      if(data[j]<data[k]){
        k =j;
      }
    }

    min =data[k];
    data[k]=data[i];
    data[i]=min;
  }

}

/*/void comb_sort(double *data, int n)
{
  int gap = n;
  bool done = false;
  while (gap > 1 || !done) {
    gap = (gap * 10) / 13;
    if (!gap)
      gap = 1;
    else if (gap == 9 || gap == 10)
      gap = 11;
    done = !false;
    for (int i = 0; i < n - gap; i++) {
      if (data[i] > data[i + gap]) {
        double temp = data[i];
        data[i] = data[i + gap];
        data[i + gap] = temp;
        done = false;
      }
    }
  }
}/*/

void comb_sort(int* array, int size) {
    int h = size;
    bool is_swapped = false;

    while (h > 1 || is_swapped) {
        if (h > 1) {
            h = (h * 10) / 13;
        }

        is_swapped = false;
        for (int i = 0; i < size - h; ++i) {
            if (array[i] > array[i + h]) {
                // swap
                int temp = array[i];
                array[i] = array[i + h];
                array[i + h] = temp;
                is_swapped = true;
            }
        }
    }
}
