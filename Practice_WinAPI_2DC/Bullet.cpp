#include "framework.h"
#include "Bullet.h"

Bullet::Bullet()
{
	m_fDir = 1.f;
}
Bullet::~Bullet()
{
}


void Bullet::Update()
{

		fPoint Pos = GetPos();

		Pos.y += 1000.f * (float)m_fDir * fDT;

		SetPos(Pos);

}

void Bullet::Render(HDC _dc)
{
	fPoint pospos=GetPos();
	fPoint scasca=GetScale();
	Ellipse(_dc,
		pospos.x - scasca.x / 2,
		pospos.y - scasca.y / 2,
		pospos.x + scasca.x / 2,
		pospos.y + scasca.y / 2);
}

