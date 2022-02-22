/*�̱��� ��ũ�� ����*/
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
/*static ���� ������ �Ҵ��Ѵ� <- static�� ���α׷� ������ �� ����� ����
�� �𸣰ڴٸ� SINGLETON: �ϳ���  ������ �ִ� �� ������ �������*/

// �̱��� Ŭ���� ����
template <typename T>
class SingleTon
{
protected:
	//�̱��� �ν��Ͻ� �����ϱ�
	static T* _instance;

	SingleTon() {};
	~SingleTon() {};

public:
	static T* getInst()
	{
		//�̱��� ��ü�� ������ ���� ����� ����.
		if (nullptr == _instance)
			_instance = new T;

		return _instance;
	}
	void release()
	{
		//�̱��� ������ ����
		if (nullptr != _instance)
		{
			delete _instance;
			_instance = nullptr;
		}
	}

};
//�̱��� �ν��Ͻ� ����
template <typename T>
T* SingleTon<T>::_instance = nullptr;