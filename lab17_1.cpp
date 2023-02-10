#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;

void showData(double *,int,int);

void randData(double *,int,int);

void findRowSum(const double *,double *,int,int);

void findColSum(const double *,double *,int,int);

int main(){
	srand(time(0));
	const int N = 6, M = 8;
	double data[N][M] = {};
	double sum1[N] = {};
	double sum2[M] = {};
	double *dPtr = data[0];
	randData(dPtr,N,M);
	showData(dPtr,N,M);
	
	cout << "---------------------------------------------\n";
	
	findRowSum(dPtr,sum1,N,M);
	showData(sum1,N,1);
	
	cout << "---------------------------------------------\n";
	
	findColSum(dPtr,sum2,N,M); 
	showData(sum2,1,M);
}

void showData(double *a,int b,int c){
    cout << fixed << setprecision(2);
    for(int i = 0; i < b*c; i++){
        cout << a[i];
        if((i+1)%c == 0) cout << endl;
        else cout << " ";
    }
}

void randData(double *a,int b,int c){
    for(int i = 0; i < b*c; i++){
        *a = rand()%101/100.0;
		a++;
    }
}

void findRowSum(const double *a,double *b,int M,int N){
	double sum = 0;
	for(int i = 0 ; i < M*N ; i++){
	    sum += a[i];
		if((i+1)%N == 0){
			*b = sum;
			b++;
			sum = 0;
		}
	}
}

void findColSum(const double *a,double *b,int N,int M){
	for(int j = 0 ; j < M ; j++){
		*b++ = 0;
	}
	b -= M;
	
	for(int i = 0 ; i < M*N ; i++){
		*b++ += *a++;
		if((i+1)%M == 0){
			b -= M;
		}
	}
}

