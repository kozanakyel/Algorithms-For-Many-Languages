#include <iostream>
#include <climits>
#include <cstdlib>
#include <cmath>

using namespace std;


void print_array(int *arr, int l);
int parent(int);
int left(int);
int right(int);
void swap(int*, int*);
void min_heapify(int A[], int i, int n);
int * build_min_heap(int A[], int n);
void heap_insert(int A[], int key, int n);
int heap_extract_min(int * A, int n);
int * rand_arr_stdid(long int id, int length);
void write_extract_min(int *arr, int length);
int * sort_kfactor(int A[], int k, int length);
void gettime_ksort(int * arr, int k, int n);
int partition(int* A, int p, int r);
void quicksort(int* A, int p, int r);
void gettime_quicksort(int *arr, int p, int r);
int find_optimized_k(int * A, int n);

int main(){
  long long int stdno = 20190808020;

  for(int i = 100; i <= 100000; i=i*10){
    cout << "--------------------------------" << endl;
    int * A = rand_arr_stdid(stdno, i);
    int optimized_k = find_optimized_k(A, i);
    gettime_ksort(A, optimized_k, i);
    gettime_quicksort(A, 0, i);
    cout << "--------------------------------" << endl;
  }

  //You could use for debugging our algorthms corecctness:
  /*   
  int * p = rand_arr_stdid(stdno, 100);
  int k = find_optimized_k(p, 100);
  int * p_sorted = sort_kfactor(p, k, 100);
  cout << "---- write kfactor sorted array ----------------" << endl;
  print_array(p_sorted, 100);

  cout << "------ write quicksort sorted array ---------- " << endl;
  quicksort(p, 0, 100);
  print_array(p, 100);
  */

}

int * sort_kfactor(int A[], int k, int length){
  int *result = new int[length];
  int *H = new int[k+1];
  int j, i = 0;

  for(int a = 0; a < k+1; a++){
    H[a] = A[a];
  }
  k = k+1;
  build_min_heap(H, k);
  j = k;
  while(k > 0){
    result[i++] = heap_extract_min(H, k);
    k = k-1;
    if(j < length){
      heap_insert(H, A[j++], k);
      k = k+1;
    }
  }
  return result;
}

void gettime_ksort(int *arr, int k, int n){
  struct timespec start, finish;
  double elapsed;
  clock_gettime(CLOCK_MONOTONIC, &start);

  int * p100 = sort_kfactor(arr, k, n);
  
  clock_gettime(CLOCK_MONOTONIC, &finish);

  elapsed = (finish.tv_sec - start.tv_sec);
  elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;  
  cout << "Min-Heap: A " << n << " elements array and k: " << k << " time calculation is: "  << elapsed << " ms"  << endl; 
}

void gettime_quicksort(int *arr, int p, int r){
  struct timespec start, finish;
  double elapsed;
  clock_gettime(CLOCK_MONOTONIC, &start);

  quicksort(arr, p, r);
  
  clock_gettime(CLOCK_MONOTONIC, &finish);

  elapsed = (finish.tv_sec - start.tv_sec);
  elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;  
  cout << "Quicksort: A " << r << " elements array " << " time calculation is: "  << elapsed << " ms"  << endl; 
}

int partition(int* A, int p, int r){
	int pivot = A[p];
	int i = p - 1;
	int j = r;
	int temp;

	while(true){
		do{j--;}while(A[j] > pivot);
    do{i++;}while(A[i] < pivot);

		if(i < j){
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}else{
			return j;
		}
	}
}

void quicksort(int* A, int p, int r){
	if(p < r - 1){
		int q = partition(A, p, r);
		quicksort(A, p , q+1);
		quicksort(A, q+1, r);
	}
}

int find_optimized_k(int * A, int n){
  int k = 0;
  int * sorted_A = sort_kfactor(A, n-1, n);
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(A[i] == sorted_A[j] && abs(j-i) > k)
        k = abs(j-i);
    }
  } 
  return k;
}

void write_extract_min(int *arr, int length){
  cout << "start extract min...\n";
  for(int i = length; i >= 0; i--){
    print_array(arr, i);
    cout << "extract...." << heap_extract_min(arr, i) << endl;
  }
}

int *rand_arr_stdid(long int id, int length){
  unsigned long int std_no;
  std_no = id;

  srand(std_no);
  int *r = new  int[length];
  for(int i = 0; i < length; i++){
    r[i] = rand();
  }
  return r;
}

void print_array(int *arr, int l){
  for(int i = 0; i < l; i++){
    cout << arr[i] << " ";
  } 
  cout << endl;
}

int parent(int i){
  return (i-1)/2;
}

int left(int i){
  return 2*i+1;
}

int right(int i){
  return 2*i+2;
}

void swap(int* x, int* y){
  int temp = *x;
  *x = *y;
  *y = temp;
}

void min_heapify(int A[], int i, int n){
  int smallest = i;
  int l = left(i);
  int r = right(i);
  if(l < n && A[l] < A[i])
    smallest = l;
  if(r < n && A[r] < A[smallest])
    smallest = r;
  if(smallest != i){
    swap(&A[i], &A[smallest]);
    min_heapify(A, smallest, n);
  }
}

int * build_min_heap(int H[], int k){
  for(int i = k/2; i >= 0; i--){
    min_heapify(H, i, k);
  }
  return H;
}

void heap_insert(int A[], int key, int n){
  int i = n;
  while(i > 0 && A[parent(i)] > key){
    A[i] = A[parent(i)];
    i = parent(i);
  } 
  A[i] = key;
}



int heap_extract_min(int A[], int n){
  if(n <= 0){
    return INT_MAX;
  }
  int min = A[0];
  A[0] = A[n-1];
  n = n-1;
  min_heapify(A, 0, n);
  return min;
}
