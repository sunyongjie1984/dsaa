#include <iostream>
#include <string>

int main()
{
    char c0 = 'a';                 // �ַ����Ͷ���c0Ϊnon-const
    char* p0_c0 = &c0;             // ָ��non-const�ַ����Ͷ����ָ�����Ͷ���p0_c0Ϊnon-const
    // ����Ա����ͨ��p0_c0�޸�c0������Ա�����޸�p0_c0��ֵ�����ı�ָ������ָ��
    char* const p1_c0 = &c0;       // ָ��non-const�ַ����Ͷ����ָ�����Ͷ���p1_c0Ϊconst
    // ����Ա����ͨ��p1_c0�޸�c0������Ա������Ҳ�������޸�p1_c0��ֵ�����ı�ָ������ָ��
    const char* p2_c0 = &c0;       // ָ��non-const��const�ַ����Ͷ����ָ�����Ͷ���p2_c0Ϊnon-const
    // ����Ա������Ҳ������ͨ��p2_c0�޸�c0������Ա�����޸�p2_c0��ֵ�����ı�ָ������ָ��
    const char* const p3_c0 = &c0; // ָ��non-const��const�ַ����Ͷ����ָ�����Ͷ���p3_c0Ϊconst
    // ����Ա������Ҳ������ͨ��p3_c0�޸�c0������Ա������Ҳ�������޸�p3_c0��ֵ�����ı�ָ������ָ��

    char const c1 = 'a';           // �ַ����Ͷ���c1Ϊconst
    const char* p0_c1 = &c1;       // ָ��non-const��const�ַ����Ͷ����ָ�����Ͷ���p0_c1Ϊnon-const
    // ����Ա������Ҳ������ͨ��p0_c1�޸�c1������Ա�����޸�p0_c1��ֵ�����ı�ָ������ָ��
    const char* const p1_c1 = &c1; // ָ��non-const��const�ַ����Ͷ����ָ�����Ͷ���p1_c1Ϊconst
    // ����Ա������Ҳ������ͨ��p1_c1�޸�c1������Ա������Ҳ�������޸�p1_c1��ֵ�����ı�ָ������ָ��

    const char c2 = 'a';           // �ַ����Ͷ���c2Ϊconst���Ҳ�ϲ���Ķ��巽ʽ���������c1������ͬ

    // ����p0_c0��p1_c0��p2_c0��p3_c0��p0_c1��p1_c1����ָ��---�ַ����Ͷ���---��ָ��

    //char* p2_c1 = &c1;           // error��cannot convert from 'const char *' to 'char *'
    // ����p2_c1��ָ��non-const�ַ����Ͷ���ģ���ζ�ų���Ա����ͨ����ָ��Ľ�
    // �������޸�p2_c1��ָ��Ķ��󣬶�c1��const������ì�ܵġ�
    //char* const p3_c1 = &c1;     // ͬ��



    // �������䣬c++ primer�����Լ������
    char ca1[] = {'C', '+', '+'};        // no null, not C-style string
    char ca2[] = {'C', '+', '+', '\0'};  // explicit null
    char ca3[] = "C++";     // null terminator added automatically
    char const *cp = "C++"; // null terminator added automatically
    char *cp1 = ca1;        // points to first element of a array, but not C-style string
    char *cp2 = ca2;        // points to first element of a null-terminated char arra
    // ca1 �� cp1 ������ C ����ַ�����ca1 ��һ������������ null ���ַ����飬��ָ�� cp1 ָ�� ca1��
    // ��ˣ���ָ��Ĳ������� null ���������顣��������������C����ַ�������������ּ���ָ�������
    // ��һ��Ԫ�ص�ָ�롣���ǣ�ca2 �� ca3 �ֱ���ָ����������һ��Ԫ�ص�ָ�롣

    // warning
    // ������ζ���Ҫ���������Ƕ�����һ��ָ�룬�ٲ�Ҫ�����Ƕ�����һ���ַ��������ˡ�
    // 


    // ָ��non-const��const�ַ��Ͷ����ָ�����qΪnon-const
    // ����Ա������Ҳ������ͨ��qȥ�޸�c����ַ���������ĸ������Ա�����޸�q��ֵ���Ըı�q��ָ��
    char const * q = "I love China";
    q = "I love American"; // ok
    // *q = 'a'; �Ա�*p = 'a'���Կ���һ���Ǳ����ܲ���ͨ����һ���Ǳ���ͨ�����������б�����


    // ָ��non-const�ַ��Ͷ����ָ�����ppΪnon-const
    // ����Ա����ͨ��ppȥ�޸�c����ַ���������ĸ������Ա�����޸�pp��ֵ���Ըı�pp��ָ��
    // ���ǣ�����һ�������������ͨ��������ʱ����������Ϊ����c����ַ����ǳ����ɣ��������޸�
    char * pp = "I love China";

    pp = "I love American"; // ok
    pp++;                   // ok

    // *p = 'a'; �������ͨ�����������оͻ����














    // C++ ����ͨ��(const)char*���͵�ָ��������C����ַ�����һ����˵������ʹ��ָ�����������������
    // C ����ַ�����ÿ�ζ�ָ����в��Բ����� 1��ֱ����������� null Ϊֹ
    const char *cp3 = "some value";
    while (*cp3) {
        // do something to *cp
        ++cp3;
    }
    // while ����ѭ�������Ƕ� const char* ���͵�ָ�� cp ���н����ã����ж� cp ��ǰָ����ַ��� true ֵ
    // ���� false ֵ����ֵ�������ǳ� null ��������ַ��������ѭ��ֱ�� cp ָ������ַ������ null ʱ��
    // ѭ��������while ѭ���������Ҫ�Ĵ����cp ��1�������ƶ�ָ��ָ�������е���һ���ַ�
    // ��� cp ��ָ����ַ�����û�� null �����������ѭ������ʧ�ܡ���ʱ��ѭ����� cp ָ���λ�ÿ�ʼ������
    // ֱ�������ڴ���ĳ�� null ������Ϊֹ

    // cstring �� string.h ͷ�ļ��� C++ �汾���� string.h ���� C �����ṩ�ı�׼�⡣
    // ���ݸ���Щ��׼�⺯�����̵�ָ�������з���ֵ������ָ���� null �������ַ������еĵ�һ��Ԫ�ء�
    // ����һЩ��׼�⺯�����޸Ĵ��ݸ������ַ�������Щ�������ٶ��������޸ĵ��ַ��������㹻��Ŀռ�
    // ���ձ����������ɵ��ַ�������Ա����ȷ��Ŀ���ַ��������㹻��
    // C++ �����ṩ��ͨ�Ĺ�ϵ������ʵ�ֱ�׼������ string �Ķ���ıȽϡ���Щ������Ҳ�����ڱȽ�ָ��
    // C����ַ�����ָ�룬��Ч��ȴ�ܲ���ͬ��ʵ���ϣ���ʱ�Ƚϵ���ָ���ϴ�ŵĵ�ֵַ��������������ָ����ַ�����
    // if (cp1 < cp2) // compares addresses, not the values pointed to
    // ��� cp1 �� cp2 ָ��ͬһ�����е�Ԫ�أ������������λ�ã����������ʽ��Ч�ڱȽ��� cp1 �� cp2
    // �д�ŵĵ�ַ�����������ָ��ָ��ͬ�����飬��ñ��ʽʵ�ֵıȽ�û�ж��塣
    // �ַ����ıȽϺͱȽϽ���Ľ��Ͷ���ʹ�ñ�׼�⺯�� strcmp ���У�

    const char *cp4 = "A string example";
    const char *cp5 = "A different string";
    int i = strcmp(cp4, cp5);    // i is positive
    i = strcmp(cp5, cp4);        // i is negative
    i = strcmp(cp4, cp4);        // i is zero
    // ��׼�⺯�� strcmp �� 3 �ֿ��ܵķ���ֵ���������ַ�����ȣ��򷵻� 0 ֵ������һ���ַ������ڵڶ����ַ�����
    // �򷵻����������򷵻ظ�����

    // �����߱���ȷ��Ŀ���ַ��������㹻�Ĵ�С
    // ���ݸ���׼�⺯�� strcat �� strcpy �ĵ�һ��ʵ�������������㹻��Ŀռ��������ɵ��ַ�����
    // ���´�����Ȼ��ʾ��һ��ͨ�����÷�������ȴ��Ǳ�ڵ����ش���
    // Dangerous: What happens if we miscalculate the size of largeStr?
    char largeStr[16 + 18 + 2];         // will hold cp1 a space and cp2
    strcpy(largeStr, cp1);              // copies cp1 into largeStr
    strcat(largeStr, " ");              // adds a space at end of largeStr
    strcat(largeStr, cp2);              // concatenates cp2 to largeStr
    // prints A string example A different string
    std::cout << largeStr << std::endl;
    // �����������Ǿ�������� largeStr ��Ҫ�Ĵ�С��ͬ���أ���� cp1 �� cp2 ��ָ����ַ�����С�����˱仯��
    // largeStr ����Ҫ�Ĵ�С��������󡣲��ҵ��ǣ���������������ĳ���Ӧ�÷ǳ��㷺����������������׳���
    // ���������صİ�ȫ©����

    // ʹ�� strn ��������C����ַ���
    // �������ʹ�� C ����ַ�������ʹ�ñ�׼�⺯�� strncat �� strncpy �� strcat �� strcpy ��������ȫ��

    char largeStr2[16 + 18 + 2]; // to hold cp1 a space and cp2
    strncpy(largeStr2, cp1, 17); // size to copy includes the null
    strncat(largeStr2, " ", 2);  // pedantic, but a good habit
    strncat(largeStr2, cp2, 19); // adds at most 18 characters, plus a null
    // ʹ�ñ�׼�⺯�� strncat �� strncpy �ľ������ڿ����ʵ��ؿ��Ƹ����ַ��ĸ������ر����ڸ��ƺʹ����ַ���ʱ��
    // һ��Ҫʱ�̼�ס���Ͻ����� null���ڶ����ַ���ʱҪ�м�Ԥ����� null�ַ��Ŀռ䣬��Ϊÿ�ε��ñ�׼�⺯����
    // �������Դ˽����ַ��� largeStr����������ϸ����һ����Щ��׼�⺯���ĵ��ã�

    // ���� strncpy ʱ��Ҫ���� 17 ���ַ����ַ��� cp1 �������ַ������Ͻ����� null�����´洢������ null
    // �Ŀռ��Ǳ�Ҫ�ģ����� largeStr �ſ�����ȷ�ؽ��������� strncpy ���ַ��� largeStr �ĳ��� strlen 
    // ֵ�� 16����ס����׼�⺯�� strlen ���ڼ��� C ����ַ����е��ַ������������� null��������

    // ���� strncat ʱ��Ҫ���� 2 ���ַ���һ���ո�ͽ������ַ�������ֵ�� null�����ý������ַ��� largeStr
    // �ĳ����� 17��ԭ�����ڽ��� largeStr �� null ������ӵĿո񸲸��ˣ�Ȼ���ڿո����д���µĽ����� null��

    // �ڶ��ε��� strncat ���� cp2 ʱ��Ҫ���� cp2 �������ַ��������ַ��������� null�����ý������ַ��� 
    // largeStr �ĳ����� 35��cp1 �� 16 ���ַ��� cp2 �� 18 ���ַ����ټ��Ϸָ��������ַ�����һ���ո�

    // ���������У��洢 largeStr �������Сʼ�ձ���Ϊ 36��������������

    // ֻҪ������ȷ����� size ʵ�ε�ֵ��ʹ�� strn �汾Ҫ��û�� size �����ļ򻯰汾����ȫ�����ǣ����Ҫ��Ŀ��
    // ���鸴�ƻ򴮽ӱ��� size ������ַ������������������Ȼ�ᷢ�������Ҫ���ƻ򴮽ӵ��ַ�����ʵ��Ҫ����
    // �򴮽ӵ� size �����ǻ᲻����ذ������ɵ��ַ����ض��ˡ��ض��ַ������������Ҫ��ȫ���������Ǵ���ġ�
    return 0;
}
