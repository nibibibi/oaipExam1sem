#include <stdio.h>
#include <conio.h>
#include <locale.h>

// ВНИМАНИЕ!!!!!
// этот проект пока только для запуска и проверки (демонстрации) в каком коде (прямом, обратном или дополнительном)
// хранятся числа с фиксированной и с плавающей точкой (запятой)
// Более подробно с типами данных используемых в программе мы будем знакомиться позже


//------------------------------  long  int ---------------------------------------------

//int main()     
//{
//	struct pole
//	{
//		unsigned i1 : 1, i2 : 1, i3 : 1, i4 : 1, i5 : 1, i6 : 1, i7 : 1, i8 : 1,
//          i9 : 1, i10 : 1, i11 : 1, i12 : 1, i13 : 1, i14 : 1, i15 : 1, i16 : 1,
//	     i17 : 1, i18 : 1, i19 : 1, i20 : 1, i21 : 1, i22 : 1, i23 : 1, i24 : 1,
//	     i25 : 1, i26 : 1, i27 : 1, i28 : 1, i29 : 1, i30 : 1, i31 : 1, i32 : 1;
//	} *p;
//
//	setlocale(0, "Rus");
//	long  int k;
//	puts("введите число типа LONG ");
//	scanf("%ld", &k);
//	p = (pole*)&k;
//	printf("Знак                        Число");
//	printf("\n %d   %d %d %d %d %d %d %d",
//		p->i32, p->i31, p->i30, p->i29, p->i28, p->i27, p->i26, p->i25);
//	printf("   %d %d %d %d %d %d %d %d",
//		p->i24, p->i23, p->i22, p->i21, p->i20, p->i19, p->i18, p->i17);
//	printf("   %d %d %d %d %d %d %d %d",
//		p->i16, p->i15, p->i14, p->i13, p->i12, p->i11, p->i10, p->i9);
//	printf("   %d %d %d %d %d %d %d %d",
//		p->i8, p->i7, p->i6, p->i5, p->i4, p->i3, p->i2, p->i1);
//	fflush(stdin);
//	getchar();
//	return 0;
//}

//------------------------------  float  ---------------------------------------------

//
//int main()     
//{
//	struct pole
//	{unsigned i1 : 1, i2 : 1, i3 : 1, i4 : 1, i5 : 1, i6 : 1, i7 : 1, i8 : 1,
//	      i9 : 1, i10 : 1, i11 : 1, i12 : 1, i13 : 1, i14 : 1, i15 : 1, i16 : 1,
//	     i17 : 1, i18 : 1, i19 : 1, i20 : 1, i21 : 1, i22 : 1, i23 : 1, i24 : 1,
//	     i25 : 1, i26 : 1, i27 : 1, i28 : 1, i29 : 1, i30 : 1, i31 : 1, i32 : 1;
//	} *p;     
//	setlocale(0, "Rus");
//
//	float k;
//	puts("введите число типа FLOAT ");
//	scanf("%f", &k);
//	p = (pole*)&k;
//	int *n = (int*)&k;
//	printf("\n %X \n",*n);
//	printf("Знак  Характеристика                 Мантисса");
//	printf("\n %d   %d %d %d %d %d %d %d %d",
//		p->i32, p->i31, p->i30, p->i29, p->i28, p->i27, p->i26, p->i25, p->i24);
//	printf("   %d %d %d %d %d %d %d",
//		p->i23, p->i22, p->i21, p->i20, p->i19, p->i18, p->i17);
//	printf(" %d %d %d %d %d %d %d %d",
//		p->i16, p->i15, p->i14, p->i13, p->i12, p->i11, p->i10, p->i9);
//	printf(" %d %d %d %d %d %d %d %d",
//		p->i8, p->i7, p->i6, p->i5, p->i4, p->i3, p->i2, p->i1);
//	fflush(stdin);
//	getchar();
//	return 0;
//}

//------------------------------  double  ---------------------------------------------

//int main()    
//{
//	struct pole
//	{
//		unsigned i1 : 1, i2 : 1, i3 : 1, i4 : 1, i5 : 1, i6 : 1, i7 : 1, i8 : 1,
//          i9 : 1, i10 : 1, i11 : 1, i12 : 1, i13 : 1, i14 : 1, i15 : 1, i16 : 1,
//	      i17 : 1, i18 : 1, i19 : 1, i20 : 1, i21 : 1, i22 : 1, i23 : 1, i24 : 1,
//	      i25 : 1, i26 : 1, i27 : 1, i28 : 1, i29 : 1, i30 : 1, i31 : 1, i32 : 1,
//		  i33 : 1, i34 : 1, i35 : 1, i36 : 1, i37 : 1, i38 : 1, i39 : 1, i40 : 1,
//		  i41 : 1, i42 : 1, i43 : 1, i44 : 1, i45 : 1, i46 : 1, i47 : 1, i48 : 1,
//	      i49 : 1, i50 : 1, i51 : 1, i52 : 1, i53 : 1, i54 : 1, i55 : 1, i56 : 1,
//	      i57 : 1, i58 : 1, i59 : 1, i60 : 1, i61 : 1, i62 : 1, i63 : 1, i64 : 1;
//	} *p;    
//	setlocale(0, "Rus");
//	double k;
//	puts("введите число типа DOUBLE ");
//	scanf("%lf", &k);
//	p = (pole*)&k;
//	printf("Знак      Характеристика                 Мантисса");
//	printf("\n %d  %d %d %d %d %d %d %d %d %d %d %d",
//		p->i64, p->i63, p->i62, p->i61, p->i60, p->i59, p->i58,
//		p->i57, p->i56, p->i55, p->i54, p->i53);
//
//	printf("   %d %d %d %d", p->i52, p->i51, p->i50, p->i49);
//	printf(" %d %d %d %d %d %d %d %d",
//		p->i48, p->i47, p->i46, p->i45, p->i44, p->i43, p->i42, p->i41);
//	printf(" %d %d %d %d %d %d %d %d",
//		p->i40, p->i39, p->i38, p->i37, p->i36, p->i35, p->i34, p->i33);
//	printf(" %d %d %d %d %d %d", p->i32, p->i31, p->i30, p->i29, p->i28, p->i27);
//	printf("\n%27c %d %d", ' ', p->i26, p->i25);
//	printf(" %d %d %d %d %d %d %d %d",
//		p->i24, p->i23, p->i22, p->i21, p->i20, p->i19, p->i18, p->i17);
//	printf(" %d %d %d %d %d %d %d %d",
//		p->i16, p->i15, p->i14, p->i13, p->i12, p->i11, p->i10, p->i9);
//	printf(" %d %d %d %d %d %d %d %d",
//		p->i8, p->i7, p->i6, p->i5, p->i4, p->i3, p->i2, p->i1);
//	fflush(stdin);
//	getchar();
//	return 0;
//}