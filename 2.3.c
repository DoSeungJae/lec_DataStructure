#include <stdio.h>
#define NO_OF_TERMS 20
//���׽��� ������ ����ü�� �̿��Ͽ� ����ϴ� �˰����̴�.


typedef struct {
	int coef;//���
	int expon; //����

}Term;

int Cs;
int Ce;

void insert(Term poly[], int avail, int coef, int expon) { //������� ����.
	poly[avail].coef = coef;
	poly[avail].expon = expon;


}

void Poly_Add(Term poly[], int As, int Ae, int Bs, int Be, int* avail) { //As,Bs�� ���� A��, B���� ������� �Ǵ� �κ�(���ۺκ�)�̰�, *e�� ���� ���κ���.
	Cs = *avail; //���� ���� ������
	int sumCoef = 0;

	//printf("%d", Cs);



	while (As <= Ae && Bs <= Be) {
		if (poly[As].expon == poly[Bs].expon) {//A�� �װ� B�� ���� ������ ���� ��쿡
			sumCoef = poly[As].coef + poly[Bs].coef;
			if (sumCoef != 0) {


				//insert(sumCoef, poly[As].expon)
				poly[*avail].coef = sumCoef;
				poly[*avail].expon = poly[As].expon;
				//insert(sumCoef, poly[As].expon)
				As += 1; //A�� B�Ѵ� ����߱� ������ 
				Bs += 1; //�Ѵ� ������� �ε����� 1�� ����.
				*avail += 1; //C�׿��� ����� ������ �ε��� 1����.


			}

			else { //sumCoef==0 ��ġ�� ������Ŵ, ���� �ҰŵǹǸ�
				As += 1;
				Bs += 1;


			}
		}
		else if (poly[As].expon > poly[Bs].expon) { //A�װ� B���� ������ �ٸ����(A���� ���� ������ �� ū���)
			//insert(poly[As].coef, poly[As].expon)
			poly[*avail].coef = poly[As].coef;
			poly[*avail].expon = poly[As].expon;
			//insert(poly[As].coef, poly[As].expon)
			As += 1; //A���� ���� �߰��Ǿ����Ƿ� A���� �ε����� 1����
			*avail += 1;


		}
		else if (poly[Bs].expon > poly[As].expon) {  //(B���� ���� ������ �� ū ���
			//insert(poly[Bs].coef,poly[Bs].expon)
			poly[*avail].coef = poly[Bs].coef;
			poly[*avail].expon = poly[Bs].expon;
			//insert(poly[Bs].coef,poly[Bs].expon)

			Bs += 1; //B���� ���� �߰��Ǿ����Ƿ� B���� �ε����� 1 ����
			*avail += 1;
		}




	}


	for (int i = As; i <= Ae; i++) {
		//insert(poly[i].coef,poly[i].expon) //A���� �ܿ��� ���
		poly[*avail].coef = poly[i].coef;
		poly[*avail].expon = poly[i].expon;
		*avail += 1;

		//insert(poly[i].coef,poly[i].expon)
	}

	for (int i = Bs; i <= Be; i++) {
		//insert(poly[i].coef,poly[i].expon)  //B���� �ܿ��� ���
		poly[*avail].coef = poly[i].coef;
		poly[*avail].expon = poly[i].expon;
		*avail += 1;

		//insert(poly[i].coef,poly[i].expon)
	}

	Ce = *avail - 1; //���� ���� ����

}

void Print_Poly(Term poly[], int As, int Ae, int Bs, int Be, int avail) { //���� ����ϴ� �Լ�

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