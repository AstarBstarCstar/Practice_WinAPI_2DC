/*�̱��� ��ũ�� ����*/
#define SINGLETON(type)			\
													\
public:											\
	static type* GetInst()				\
	{												\
		static type _Instance;			\
		return &_Instance;				\
	}												\
private:											\
	  type();									\
	~type();										
/*static ���� ������ �Ҵ��Ѵ� <- static�� ���α׷� ������ �� ����� ����
SINGLETON: �ϳ���  ������ �ִ� �� !�������*/








/*�̱��� Ŭ���� ���Ǻ�
 ��ũ�� ���ǰ� ���� �� �� ����մϴ�.*/
//template <typename T>
//class SingleTon
//{
//protected:
//	//�̱��� �ν��Ͻ� �����ϱ�
//	static T* _instance;
//
//	SingleTon() {};
//	~SingleTon() {};
//
//public:
//	static T* getInst()
//	{
//		//�̱��� ��ü�� ������ ���� ����� �����մϴ�.
//		if (nullptr == _instance)
//			_instance = new T;
//
//		return _instance;
//	}
//	void release()
//	{
//		//�̱����� ������ �����մϴ�.
//		if (nullptr != _instance)
//		{
//			delete _instance;
//			_instance = nullptr;
//		}
//	}
//
//};
////�̱��� �ν��Ͻ� ����
//template <typename T>
//T* SingleTon<T>::_instance = nullptr;