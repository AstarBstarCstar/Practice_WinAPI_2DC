/*싱글톤 매크로 정의*/
//진짜 개좆같네 싱글톤 문제 있는줄 알고 한참 찾아다니고 아예 복붙해도 안되길래 답없다 했는데 씨빨 SINGLETON을 씨빨 SINGLETONE으로 쓰냥ㅁㄴ이;ㅏㅁㅇ
#define SINGLETON(type)			\
													\
public:											\
	static type* getInst()					\
	{												\
		static type _instance;			\
		return &_instance;				\
	}												\
private:											\
	type();										\
	~type();										

/*static 정적 영역에 할당한다 <- static은 프로그램 시작할 때 만들어 진다
잘 모르겠다면 SINGLETON: 하나만  가질수 있는 얘 정도로 기억하자*/





/*싱글톤 클래스 정의부
 매크로 정의가 오류 날 시 사용합니다.*/
//template <typename T>
//class SingleTon
//{
//protected:
//	//싱글톤 인스턴스 선언하기
//	static T* _instance;
//
//	SingleTon() {};
//	~SingleTon() {};
//
//public:
//	static T* getInst()
//	{
//		//싱글톤 객체가 없으면 새로 만들어 전달합니다.
//		if (nullptr == _instance)
//			_instance = new T;
//
//		return _instance;
//	}
//	void release()
//	{
//		//싱글톤이 있으면 해제합니다.
//		if (nullptr != _instance)
//		{
//			delete _instance;
//			_instance = nullptr;
//		}
//	}
//
//};
////싱글톤 인스턴스 선언
//template <typename T>
//T* SingleTon<T>::_instance = nullptr;