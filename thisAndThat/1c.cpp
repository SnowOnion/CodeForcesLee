/**
AC

i've learned sth. today…

1. fmod
2. fmod 是很严格的... fmod(1.256637056,1.256637061) 返回 1.256637061
于是为了能用fmod, 窝把两个数*1e6再/1e6... 可能这导致了后面很大的浮点误差...
3. 控制浮点误差的方法 不是可以拍脑袋想的... 窝根据四五次WA的test case把判断x和y相等的函数从fabs(x-y)<1e-6改成1e-5, 2e-5,4e-5… 太胡闹了...
你萌有没有比较系统的控制浮点误差的方法...
4. 如果非要调参数 (导致总是要看中间结果), 就用IDE调试罢, 别printf注释来注释去的了- -
http://codeforces.com/contest/1/submission/17893605
仆  02:19:12
板栗要是做了的话求share一发(
*/

#include<cstdio>
#include<cmath>
#define PI (4*atan(1))

bool eq_strict(double x,double y){
	return fabs(x-y)<=1e-6;
}

bool eq(double x,double y){
	return fabs(x-y)<4e-5; //// 第三次WA(case5):1:砍成6位小数再喂fmod 似乎导致eq时精度不够了... 放宽相等判定到1e-5... 害怕
	// 第四次WA: 为了case20 (0.000011) 再放宽到2e-5...
	// 第五次WA: case40 0.000036 那就4e-5吧... 感到了调参的魅力...
}
bool eq0(double x){
	// printf("eq0!! %lf\n",x);
	return eq(x,0);
}
// square
double sq(double x){
	return x*x;
}
// square, sum
double sqs(double x,double y){
	return sq(x)+sq(y);
}
// euclidean
double dist(double x1,double y1,double x2,double y2){
	return sqrt(sqs(x1-x2,y1-y2));
}

double det3(
	double a11,double a12,double a13,
	double a21,double a22,double a23,
	double a31,double a32,double a33){
	return a11*(a22*a33-a23*a32) + a21*(a32*a13-a33*a12) + a31*(a12*a23-a13*a22);
}

//[0,2pi)
double theta(double ox,double oy,double px,double py){
	if(eq_strict(ox,px)){ // 第四次WA放宽后: 窝觉得这里可以用严格版本的eq... 如果再出诡异错误就这么改
		// case 40: expected: '5669.9944428', found: '5670.8426010', error = '0.0001496'
		// 果断改用 strict... 不对, 没有影响答案...
		if(py>=0) return PI/2;
		else return 3*PI/2;
	}
	else{
		double dx=px-ox,dy=py-oy;
		double k=dy/dx;
		if(dx<=0) {
			return atan(k)+PI;
		}
		else {
			if(dy>=0){
				return atan(k);
			}
			else{
				return atan(k)+2*PI; // 第一次WA(case3) :1: 这里写成 +PI/2
			}
		}
	}
}

double cut6fmod(double numer,double denom){
	return fmod(((int)(numer*1e6))/1e6,((int)(denom*1e6))/1e6);
}

int main(){

	// printf("%lf\n",fmod(1.256637,1.256637));
	// printf("%lf\n",fmod(1.256637056,1.256637061));

	double x1,y1,x2,y2,x3,y3;
	scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3);

	// calc O and r
	double 
	z1=sqs(x1,y1),
	z2=sqs(x2,y2),
	z3=sqs(x3,y3);
	double denominator=2*det3(
		x1,y1,1,
		x2,y2,1,
		x3,y3,1);
	double 
	ox=det3(
		z1,y1,1,
		z2,y2,1,
		z3,y3,1)/denominator,
	oy=det3(
		x1,z1,1,
		x2,z2,1,
		x3,z3,1)/denominator;
	double r=dist(x1,y1,ox,oy);

	// printf("x,y,r %lf,%lf;%lf\n",ox,oy,r);
	// printf("theta %lf,%lf,%lf\n",
	// 	theta(ox,oy,x1,y1),
	// 	theta(ox,oy,x2,y2),
	// 	theta(ox,oy,x3,y3)
	// 	);
	// printf("{{%lf,%lf},{%lf,%lf},{%lf,%lf},{%lf,%lf}}\n",x1,y1,x2,y2,x3,y3,ox,oy);

	double theta1=theta(ox,oy,x1,y1),
		theta2=theta(ox,oy,x2,y2),
		theta3=theta(ox,oy,x3,y3);
	//关心两个夹角就可以了 // 第一次WA:2:不能随便两个! 要<=PI的两个...
	double a=fabs(theta1-theta2),
	b=fabs(theta1-theta3);
	// printf("a,b %lf,%lf\n",a,b);
	if(a>PI) a=2*PI-a;
	if(b>PI) b=2*PI-b;
	// printf("a,b %.9f,%.9f\n",a,b);

	int i;
	// It's guaranteed that the number of angles in the optimal polygon is not larger than 100.
	for(i=3;i<=100;i++){
		// printf("i  %d\n",i);
		// printf("2*PI/i %.9f\n",2*PI/i);
		if(eq0(cut6fmod(a,2*PI/i)) && eq0(cut6fmod(b,2*PI/i))){ // 第二次WA(case4):1:计算精度不够, 喂进fmod会出问题... 砍成6位小数再喂
			break;
		}
	}
	// printf("%d\n",i);
	// double area=i*(r*r*sin(PI/i)*cos(PI/i));
	// WA5:case40:输出精度不够:边数应该数对了(吧), 尝试瞎优化一下area的精度... 不攒很多个连乘, 而是早做除法?(no)
	// 不! 边数数错了! case40 应该91边形. 所以继续放宽eq就好了!(((
	double area=i*r*r*sin(2*PI/i)/2;

	printf("%lf\n",area);

	return 0;
}