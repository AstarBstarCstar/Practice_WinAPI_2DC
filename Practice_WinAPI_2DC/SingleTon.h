/*싱글톤 매크로 정의*/
#pragma once
#define SINGLETONE(type)	\
							\
public:                     \
static type* getInst()      \
{                           \
	static type _instance;  \
	return &_instance;      \
}                           \
private:                    \
	type();                 \
	~type();      
/*static 정적 영역에 할당한다 <- static은 프로그램 시작할 때 만들어 진다
잘 모르겠다면 SINGLETON: 하나만  가질수 있는 얘 정도로 기억하자*/

// 싱글톤 클래스 정의
template <typename T>
class SingleTon
{
protected:
	//싱글톤 인스턴스 선언하기
	static T* _instance;

	SingleTon() {};
	~SingleTon() {};

public:
	static T* getInst()
	{
		//싱글톤 객체가 없으면 새로 만들어 전달.
		if (nullptr == _instance)
			_instance = new T;

		return _instance;
	}
	void release()
	{
		//싱글톤 있으면 해제
		if (nullptr != _instance)
		{
			delete _instance;
			_instance = nullptr;
		}
	}

};
//싱글톤 인스턴스 선언
template <typename T>
T* SingleTon<T>::_instance = nullptr;