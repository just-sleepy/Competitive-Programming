// Checar se existe intercessão entre duas retas

// Dadas duas retas (p1, q1) e (p2, q2)

// 1º - Caso Geral

// (p1,q1,p2) e (p1,q1,q2) possuem orientações diferentes e
// (p2,q2,p1) e (p2,q2,q1) possuem orientações diferentes.

// 2º - Retas colineares

// Há intercessão na projeção x de (p1,q1) e (p2,q2) ou
// há intercessão na projeção y de (p1,q1) e (p2,q2)

typedef struct
{
	int x, y;
} pnt;

bool collinear(pnt p, pnt q, pnt r)
{
	if(q.x<=max(p.x,r.x) && q.x>=min(p.x,r.x) && q.y<=max(p.y,r.y) && q.y>=min(p.y,r.y))
		return true;

	return false;
}

int orientation(pnt p, pnt q, pnt r)
{
	int val=(q.y-p.y)*(r.x-q.x)-(q.x-p.x)*(r.y-q.y);

	if(val==0)
		return 0;
	else if(val>0)
		return 1; // Sentido horário
	else
		return 2; // Sentido anti-horário
} 

bool intersect(pnt p1, pnt q1, pnt p2, pnt q2)
{
	int o1 = orientation(p1, q1, p2);
	int o2 = orientation(p1, q1, q2);
	int o3 = orientation(p2, q2, p1);
	int o4 = orientation(p2, q2, q1);

	if(o1!=o2 and o3!=o4) //1º Caso
		return true;

	//2° Caso

	if(o1==0 && collinear(p1, p2, q1))
		return true;

	if(o2==0 && collinear(p1, q2, q1))
		return true;

	if(o3==0 && collinear(p2, p1, q2))
		return true;

	if(o4==0 && collinear(p2, q1, q2))
		return true;

    return false;

}