///�������ݽṹ��ʵ��
/***********************************************************************
ϵͳ����: NEEQ1.0
ģ������:
�� �� ��: skiplist.cpp
����˵��:
��    ��: �����
��������: 2013-7-10   10:46:44
�޸ļ�¼:
***********************************************************************/
#include "skiplist.h"


skiplist::skiplist(bool type /* = true */)
: m_type(type)
, m_size(0)
, m_level(0)
, m_header(NULL)
, m_curr(NULL)
{
    /* initialize header skiplistnode */
    m_header = createNode(0, NULL, MAX_LEVEL);
}

skiplist::~skiplist()
{
    skiplistnode* p = m_header->forward[0];
    skiplistnode* q = NULL;

    /* delete header */
    delete [] m_header->forward;
    delete m_header;

    /* delete next skiplistnode */
    while ((q = p) != NULL)
    {
        p = q->forward[0];

        delete [] q->forward;
        delete q;

        if (!p) break;
    }
}

int32_t skiplist::add(const int32_t key, const void* val)
{
    int32_t i = 0;
    skiplistnode* p = m_header;
    skiplistnode* q = NULL;
    skiplistnode* update[MAX_LEVEL];

    /* 1.�Ӹߵ��Ͳ����½ڵ�����λ�� */
    for (i = m_level - 1; i >= 0; --i)
    {
        while ((q = p->forward[i]) && (m_type?(q->key < key):(q->key > key))) p = q; /* ����������� */
        update[i] = p; /* �Ѽ�ÿһ��key��߽ڵ� */
    }

    /* 2.�Ѵ��ڣ�����ʧ�� */
    if ((q != NULL) && (q->key == key)) return -1;

    /* 3.�����½ڵ����level */
    int32_t level = randomLevel();
    if (level > m_level)
    {
#ifdef _WIN32
        update[m_level] = m_header;
        level = ++m_level;
#else
        for (i = m_level; i < level; ++i)
        {
            update[i] = m_header;
        }
        m_level = level;
#endif
    }

    /* 4.�½ڵ� */
    q = createNode(key, val, level);

    /* 5.������ǰ�ڵ���½ڵ��ָ�� */
    for (i = 0; i < level; ++i)
    {
        q->forward[i] = update[i]->forward[i];
        update[i]->forward[i] = q;
    }

    ++m_size;
    return 0;
}

int32_t skiplist::del(const int32_t key, void*& val)
{
    int32_t i = 0;
    skiplistnode* p = m_header;
    skiplistnode* q = NULL;
    skiplistnode* update[MAX_LEVEL];

    /* 1.�Ӹߵ��Ͳ�����Ҫɾ���Ľڵ�λ�� */
    for (i = m_level - 1; i >= 0; --i)
    {
        while ((q = p->forward[i]) && (m_type?(q->key < key):(q->key > key))) p = q; /* ����������� */
        update[i] = p; /* �Ѽ�ÿһ��key��߽ڵ� */
    }

    /* 2.����ָ�롢�ͷ���Դ�����������level */
    if ((q != NULL) && (q->key == key))
    {
        /* ������߽ڵ��ָ����Ϣ */
        for (i = 0; i < m_level; ++i)
        {
            /* ��ַ�Ƚ� */
            if (update[i]->forward[i] == q)
            {
                update[i]->forward[i] = q->forward[i];
            }
        }

        /* �ͷŽڵ����Դ */
        {
            val = q->val;/* ���ظ��ⲿ�����ⲿ���л��� */
            delete [] q->forward;
            delete q;
            q = NULL;
        }

        /* ����ýڵ��level�����ģ�����Ҫ���������level */
        for (i = m_level - 1; (i >= 0) && (m_header->forward[i] == NULL); --i)
        {
            --m_level;
        }

        --m_size;
        return 0;
    }

    return -1;
}

int32_t skiplist::get(const int32_t key, void*& val)
{
    skiplistnode* p = m_header;
    skiplistnode* q = NULL;

    /* 1.�Ӹߵ��Ͳ���key�Ľڵ�λ�� */
    for (int32_t i = m_level - 1; i >= 0; --i)
    {
        while ((q = p->forward[i]) && (m_type?(q->key < key):(q->key > key))) p = q; /* ����������� */
    }

    /* 2.���� */
    if ((q != NULL) && (q->key == key))
    {
        val = q->val;
        return 0;
    }

    return -1;
}

int32_t skiplist::size() const
{
    return m_size;
}

int32_t skiplist::first(int32_t& key, void*& val)
{
    /* ����Ϊ�� */
    if (m_size == 0) return -1;

    /* ��һ���ڵ� */
    m_curr = m_header->forward[0];

    /* �쳣���� */
    if (m_curr == NULL) return -1;

    /* ��ֵ */
    key = m_curr->key;
    val = m_curr->val;

    return 0;
}

int32_t skiplist::next(int32_t& key, void*& val)
{
    /* ���ұ��� */
    if (m_curr == NULL) return -1;

    /* ��һ���ڵ� */
    m_curr = m_curr->forward[0];

    /* �������� */
    if (m_curr == NULL) return -1;

    /* ��ֵ */
    key = m_curr->key;
    val = m_curr->val;

    return 0;
}

int32_t skiplist::locate(const int32_t key)
{
    /* ��ǰ�ڵ��Ƿ�������õĽڵ� */
    if (m_curr != NULL)
    {
        if (m_curr->key == key) return 0;
    }

    skiplistnode* p = m_header;
    skiplistnode* q = NULL;

    /* 1.�Ӹߵ��Ͳ���key�Ľڵ�λ�� */
    for (int32_t i = m_level - 1; i >= 0; --i)
    {
        while ((q = p->forward[i]) && (m_type?(q->key < key):(q->key > key))) p = q; /* ����������� */
    }

    /* 2.���� */
    if ((q != NULL) && (q->key == key))
    {
        m_curr = q;
        return 0;
    }

    return -1;
}

bool skiplist::isEof()
{
    /* ���ұ��� */
    if (m_curr == NULL) return true;

    return (m_curr->forward[0] == NULL) ? true : false;
}

skiplistnode* skiplist::createNode(const int32_t key, const void* val, int32_t level)
{
    skiplistnode* one = FBASE_NEW skiplistnode;
    one->key = key;
    one->val = (void*)val;
    one->forward = FBASE_NEW skiplistnode*[level];
    memset(one->forward, '\0', sizeof(skiplistnode*)*level);
    one->level = level;
    return one;
}

int32_t skiplist::randomLevel()
{
    int32_t level = 1;

#ifdef _WIN32
    /*while ((rand() & 0xFF) < (SKIPLIST_P * 0xFF))*/
    while(rand() > (RAND_MAX * SKIPLIST_P))
#else
    while ((random() & 0xFFFF) < (SKIPLIST_P * 0xFFFF))
#endif
        level += 1;

    return (level < MAX_LEVEL) ? level : MAX_LEVEL;
}

int32_t skiplist_bid::add(const int32_t key, const void* val)
{
    int32_t i = 0;
    skiplistnode* p = m_header;
    skiplistnode* q = NULL;
    skiplistnode* update[MAX_LEVEL];

    /* 1.�Ӹߵ��Ͳ����½ڵ�����λ�� */
    for (i = m_level - 1; i >= 0; --i)
    {
        while ((q = p->forward[i]) && (m_type?(q->key < key):(q->key > key)))
        {
            p = q; /* ����������� */
        }
        update[i] = p; /* �Ѽ�ÿһ��key��߽ڵ� */
    }

    /* 2.�Ѵ��ڣ�����ʧ�� */
    if ((q != NULL) && (q->key == key))
    {
        return -1;
    }

    /* 3.�����½ڵ����level */
    int32_t level = randomLevel();
//     if (key >= m_low && key <= m_high)
//     {
//         level = m_level;
//     }
    if (level > m_level)
    {
#ifdef _WIN32
        update[m_level] = m_header;
        level = ++m_level;
#else
        for (i = m_level; i < level; ++i)
        {
            update[i] = m_header;
        }
        m_level = level;
#endif
    }

    /* 4.�½ڵ� */
    q = createNode(key, val, level);

    /* 5.������ǰ�ڵ���½ڵ��ָ�� */
    for (i = 0; i < level; ++i)
    {
        q->forward[i] = update[i]->forward[i];
        update[i]->forward[i] = q;
    }
    if (NULL != m_first_valid && ((m_type && key < m_first_valid->key && key >= m_low)
        || (!m_type && key > m_first_valid->key && key <= m_high)))
    {
        m_first_valid = m_curr = q;
    }
    ++m_size;
    return 0;
}

int32_t skiplist_bid::del(const int32_t key, void*& val)
{
    int32_t i = 0;
    skiplistnode* p = m_header;
    skiplistnode* q = NULL;
    skiplistnode* update[MAX_LEVEL];

    /* 1.�Ӹߵ��Ͳ�����Ҫɾ���Ľڵ�λ�� */
    for (i = m_level - 1; i >= 0; --i)
    {
        while ((q = p->forward[i]) && (m_type?(q->key < key):(q->key > key)))
        {
            p = q; /* ����������� */
        }
        update[i] = p; /* �Ѽ�ÿһ��key��߽ڵ� */
    }

    /* 2.����ָ�롢�ͷ���Դ�����������level */
    if ((q != NULL) && (q->key == key))
    {
        /* ������߽ڵ��ָ����Ϣ */
        for (i = 0; i < m_level; ++i)
        {
            /* ��ַ�Ƚ� */
            if (update[i]->forward[i] == q)
            {
                update[i]->forward[i] = q->forward[i];
            }
        }
        if (m_first_valid == q)
        {
            if (m_type)
            {
                if (NULL != m_first_valid->forward[0] && m_first_valid->forward[0]->key <= m_high)
                {
                    m_curr = m_first_valid = m_first_valid->forward[0];
                }
                else
                {
                    m_curr = m_first_valid = NULL;
//                     first_valid(val);
                }
            }
            else
            {
                if (NULL != m_first_valid->forward[0] && m_first_valid->forward[0]->key >= m_low)
                {
                    m_curr = m_first_valid = m_first_valid->forward[0];
                }
                else
                {
                    m_curr = m_first_valid = NULL;
//                     first_valid(val);
                }
            }
        }
        /* �ͷŽڵ����Դ */
        {
            val = q->val;/* ���ظ��ⲿ�����ⲿ���л��� */
            delete [] q->forward;
            delete q;
            q = NULL;
        }

        /* ����ýڵ��level�����ģ�����Ҫ���������level */
        for (i = m_level - 1; (i >= 0) && (m_header->forward[i] == NULL); --i)
        {
            --m_level;
        }

        --m_size;
        return 0;
    }

    return -1;
}


int32_t skiplist_bid::first_valid(void*& val)
{
    if (m_size == 0) return -1;

    if (NULL != m_first_valid)
    {
        val = m_first_valid->val;
        m_curr = m_first_valid;
        return 0;
    }

    skiplistnode* p = m_header;
    skiplistnode* q = NULL;

    /* 1.�Ӹߵ��Ͳ���key�Ľڵ�λ�� */
    for (int32_t i = m_level - 1; i >= 0; --i)
    {
        while ((q = p->forward[i]) && (m_type?(q->key < m_low):(q->key > m_high)))
        {
            p = q; /* ����������� */
        }
    }
    //
    if (NULL != q && (m_type ? (q->key <= m_high) : (q->key >= m_low)))
    {
        val = q->val;
        m_first_valid = m_curr = q;

        return 0;
    }
    return -1;
}


int32_t skiplist_bid::next_valid(void*& val)
{
    /* ���ұ��� */
    if (m_curr == NULL) return -1;

    /* ��һ���ڵ� */
    m_curr = m_curr->forward[0];

    /* �������� */
    if (m_curr == NULL) return -1;

    if (m_type ? m_curr->key <= m_high : m_curr->key >= m_low)
    {
        val = m_curr->val;
    }
    else
    {
        return -1;
    }

    return 0;
}

void skiplist_bid::set_valid_range(int32_t low, int32_t high)
{
    if (m_low == low && m_high == high)
    {
        return;
    }

    bool flag = (low > m_low || high > m_high) ? true : false;
    m_low = low;
    m_high = 0 == high ? uint_max : high;
    if (0 != m_size)
    {
        //update_first_valid(flag); // ��֤��������������
        void* val;
        first_valid(val);
    }
 }

void skiplist_bid::update_first_valid(bool flag)
{
    void* val = NULL;
    if ((flag && m_type) || (!flag && !m_type)) // ���̣���Ч�۸��������ǻ���������Ч�۸��½�
    {
        if (NULL != m_first_valid)
        {
            if (NULL != m_first_valid &&
                ((m_type && m_first_valid->key >= m_low) || (!m_type && m_first_valid->key <= m_high)))
            {
                m_curr = m_first_valid;
                return ;
            }
            skiplistnode* p = m_first_valid;
            skiplistnode* q = NULL;
            int32_t level = p->level;

            for (int32_t i = level - 1; i >= 0; --i)
            {
                while ((q = p->forward[i]) && (m_type?(q->key < m_low):(q->key > m_high)))
                {
                    p = q;
//                     if (q->level > level)
//                     {
//                         level = q->level;
//                         i = level - 1;
//                     }
                }
            }
            if (NULL != q && (m_type ? (q->key <= m_high) : (q->key >= m_low)))
            {
                m_first_valid = m_curr = q;
                return ;
            }
        }
    }
    m_curr = m_first_valid = NULL;
    first_valid(val);
}
