#include <stdio.h>
#define NO_OF_TERMS 20
//다항식의 덧셈을 구조체를 이용하여 계산하는 알고리즘이다.


typedef struct {
	int coef;//계수
	int expon; //지수

}Term;

int Cs;
int Ce;

void insert(Term poly[], int avail, int coef, int expon) { //사용하지 않음.
	poly[avail].coef = coef;
	poly[avail].expon = expon;


}

void Poly_Add(Term poly[], int As, int Ae, int Bs, int Be, int* avail) { //As,Bs는 각각 A항, B항의 계산대상이 되는 부분(시작부분)이고, *e는 항의 끝부분임.
	Cs = *avail; //계산된 항의 시작점
	int sumCoef = 0;

	//printf("%d", Cs);



	while (As <= Ae && Bs <= Be) {
		if (poly[As].expon == poly[Bs].expon) {//A의 항과 B의 항의 차수가 같은 경우에
			sumCoef = poly[As].coef + poly[Bs].coef;
			if (sumCoef != 0) {


				//insert(sumCoef, poly[As].expon)
				poly[*avail].coef = sumCoef;
				poly[*avail].expon = poly[As].expon;
				//insert(sumCoef, poly[As].expon)
				As += 1; //A와 B둘다 계산했기 때문에 
				Bs += 1; //둘다 계산대상의 인덱스를 1씩 증가.
				*avail += 1; //C항에서 써넣을 공간의 인덱스 1증가.


			}

			else { //sumCoef==0 위치만 증가시킴, 식이 소거되므르
				As += 1;
				Bs += 1;


			}
		}
		else if (poly[As].expon > poly[Bs].expon) { //A항과 B항의 차수가 다른경우(A식의 항의 차수가 더 큰경우)
			//insert(poly[As].coef, poly[As].expon)
			poly[*avail].coef = poly[As].coef;
			poly[*avail].expon = poly[As].expon;
			//insert(poly[As].coef, poly[As].expon)
			As += 1; //A항의 값만 추가되었으므로 A항의 인덱스만 1증가
			*avail += 1;


		}
		else if (poly[Bs].expon > poly[As].expon) {  //(B식의 항의 차수가 더 큰 경우
			//insert(poly[Bs].coef,poly[Bs].expon)
			poly[*avail].coef = poly[Bs].coef;
			poly[*avail].expon = poly[Bs].expon;
			//insert(poly[Bs].coef,poly[Bs].expon)

			Bs += 1; //B항의 값만 추가되었으므로 B항의 인덱스만 1 증가
			*avail += 1;
		}




	}


	for (int i = As; i <= Ae; i++) {
		//insert(poly[i].coef,poly[i].expon) //A식의 잔여항 계산
		poly[*avail].coef = poly[i].coef;
		poly[*avail].expon = poly[i].expon;
		*avail += 1;

		//insert(poly[i].coef,poly[i].expon)
	}

	for (int i = Bs; i <= Be; i++) {
		//insert(poly[i].coef,poly[i].expon)  //B식의 잔여항 계산
		poly[*avail].coef = poly[i].coef;
		poly[*avail].expon = poly[i].expon;
		*avail += 1;

		//insert(poly[i].coef,poly[i].expon)
	}

	Ce = *avail - 1; //계산된 항의 끝점

}

void Print_Poly(Term poly[], int As, int Ae, int Bs, int Be, int avail) { //식을 출력하는 함수

	//int Cs = 6;
	//int Ce = 11;

	for (int i = 0; i < avail; i++) {
		if (i == As)      printf("Polynomial A: ");
		else if (i == Bs) printf("Polynomial B: ");
		else if (i == Cs) printf("Polynomial C: ");


		printf("%d *x ^%d ", poly[i].coef, poly[i].expon);

		if (i == Ae || i == Be || i == Ce) {
			printf("\n");

		}

		else {

			printf(" + ");

		}


	}
}


int main(void) {
	Term poly[NO_OF_TERMS] = { {3,5},{2,3},{2,0},{4,4},{-2,3},{2,1} };

	int As = 0;
	int Ae = 2;
	int Bs = 3;
	int Be = 5;

	int avail = 6;
	Poly_Add(poly, As, Ae, Bs, Be, &avail);
	Print_Poly(poly, As, Ae, Bs, Be, avail);

	return 0;


}