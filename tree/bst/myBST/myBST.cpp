#include "myBST.h"

BSTNode* myBST::insert(int e, BSTNode*& in)
{
    if (nullptr == m_root) // empty tree, insert successful
    {
        m_root = new BSTNode;
        m_root->key = e;
        m_root->left = nullptr;
        m_root->right = nullptr;
        m_root->father = nullptr;
        return m_curr =m_root;
    }
    BSTNode* p;
    in = search_add(e, p);
    if (nullptr == in) // not exists, insert successful
    {
        return p;
    }
    else
        m_root->father = nullptr;
    {
        return nullptr; // insert failed because already exists in the bst tree
    }
}

void myBST::left_balance(BSTNode*& p)
{
    BSTNode* q = p->left;
    switch (q->bf)
    {
    case LH :
        p->bf = q->bf = EH;
        right_rotate(p);
        break;
    case RH :
        BSTNode* rd;
        rd = q->right;
        switch (rd->bf)
        {
        case LH :
            p->bf = RH;
            q->bf = EH;
            break;
        case EH :
            p->bf = q->bf = EH;
            break;
        case RH :
            p->bf = EH;
            q->bf = LH;
            break;
        default:
            break;
        }
        rd->bf = EH;
        left_rotate(p->left);
        right_rotate(p);
    }
    return ;
}

void myBST::left_balance_for_del(BSTNode*& p, bool& shorter)
{
    BSTNode* q = p->left;
    switch (q->bf)
    {
    case LH :
        p->bf = q->bf = EH; 
        right_rotate(p);
        shorter = true;
       break;
    case EH :
        p->bf = LH;
        q->bf = RH;
        right_rotate(p);
        shorter = false;
        break;
    case RH :
        BSTNode* rd;
        rd = q->right;
        switch (rd->bf)
        {
        case LH :
            p->bf = RH;
            q->bf = EH;
            break;
        case EH :
            p->bf = q->bf = EH;
            break;
        case RH :
            p->bf = EH;
            q->bf = LH;
            break;
        default:
            break;
        }
        rd->bf = EH;
        shorter = true;
        left_rotate(p->left);
        right_rotate(p);
    }
    return ;
}

void myBST::right_balance_for_del(BSTNode*& p, bool& shorter)
{
    BSTNode* q = p->right;
    switch (q->bf)
    {
    case EH :
        p->bf = RH;
        q->bf = LH;
        left_rotate(p);
        shorter = false;
        break;
    case RH :
        p->bf = q->bf = EH;
        shorter = true;
        left_rotate(p);
        break;
    case LH :
        BSTNode* rd;
        rd = q->left;
        switch (rd->bf)
        {
        case RH :
            p->bf = LH;
            q->bf = EH;
            break;
        case EH :
            p->bf = q->bf = EH;
            break;
        case LH :
            p->bf = EH;
            q->bf = RH;
            break;
        default:
            break;
        }
        rd->bf = EH;
        shorter = true;
        right_rotate(p->right);
        left_rotate(p);
    }
    return ;
}

void myBST::right_balance(BSTNode*& p)
{   // ��p������ƽ�⣬pһ�����Һ���
    BSTNode* q = p->right;
    switch (q->bf)
    {
    case RH :
//         p->bf = q->bf = EH;
        p->bf += LH;
        q->bf += LH;
        left_rotate(p);
        break;
    case LH :
        BSTNode* rd;
        rd = q->left;
        if (rd->bf <= RH)
        {
            p->bf += 2 * LH;
            q->bf += RH;
            rd->bf += LH;
        }
        else if (EH == rd->bf)
        {
            p->bf += LH;
            q->bf += RH;
        }
        else
        {
            p->bf += LH;
            q->bf += 2 * RH;
            rd->bf += RH;
        }
//         switch (rd->bf)
//         {
//         case RH :
//             p->bf = LH;
//             q->bf = EH;
//             break;
//         case EH :
//             p->bf = q->bf = EH;
//             break;
//         case LH :
//             p->bf = EH;
//             q->bf = RH;
//             break;
//         default:
//             break;
//         }
//         rd->bf = EH;
        right_rotate(p->right);
        left_rotate(p);
    }
    return ;
}

// int myBST::delete_avl_not_recusive(int e, bool& shorter)
// {
//     void* val;
//     BSTNode* p = search(e, val);
//     if (nullptr != p)
//     {
//         bool p_is_left = true;
//         if (p->father)
//         {
//             p_is_left = p == p->father->left ? true : false;
//         }
//         BSTNode* q = p;
//         if (nullptr == p->left && nullptr == p->right) // ��ɾ���ڵ����Һ��Ӷ�Ϊ��
//         {
//             if (EH == p->father->bf)
//             {
//                 if (p_is_left)
//                 {
//                     p->father->bf = RH;
//                     p->father->left = nullptr;
//                 }
//                 else
//                 {
//                     p->father->bf = LH;
//                     p->father->right = nullptr;
//                 }
//             }
//             else if (LH == p->father->bf)
//             {
//                 p->father->bf = EH;
//                 p->father->left = nullptr;
//             }
//             else
//             {
//                 p->father->bf = EH;
//                 p->father->right = nullptr;
//             }
//         }
//         else if (nullptr == p->right)
//         {
//             p = p->left;
//             p_is_left ? q->father->left = p : q->father->right = p;
//             p->father = q->father;
//             if (EH == p->father->bf)
//             {
//                 if (p_is_left)
//                 {
//                     p->father->bf = RH;
//                 }
//                 else
//                 {
//                     p->father->bf = LH;
//                 }
//             }
//             else if (LH == p->father->bf)
//             {
//                 p->father->bf = EH;
//             }
//             else
//             {
//                 p->father->bf = EH;
//             }
//         }
//         else if (nullptr == p->left)
//         {
//             p = p->right;
//             p_is_left ? q->father->left = p : q->father->right = p;
//             p->father = q->father;
//             if (EH == p->father->bf)
//             {
//                 if (p_is_left)
//                 {
//                     p->father->bf = RH;
//                 }
//                 else
//                 {
//                     p->father->bf = LH;
//                 }
//             }
//             else if (LH == p->father->bf)
//             {
//                 p->father->bf = EH;
//             }
//             else
//             {
//                 p->father->bf = EH;
//             }
//         }
//         else
//         {
// 
//         }
//         delete q;
//         return 1;
//     }
//     return 1;
// }

int myBST::delete_node(int e, void* val)
{
    bool flag = false;
    return delete_avl(e, val, flag);
}

int myBST::delete_avl(int e, void* val, bool& shorter)
{
    int ret = 0;
    bool left = true;
    BSTNode* curr_father;
    BSTNode* tmp;
    if (nullptr == m_root) // not found, empty tree
    {
        shorter = 0;
        m_curr = nullptr;
        m_b_first = true;
        return 1;
    }
    if (m_b_first)
    {
        m_curr = m_root;
        m_b_first = false;
    }
    if (nullptr == m_curr) // not found
    {
        shorter = 0;
        m_b_first = true;
        return 1;
    }
    if (e == m_curr->key) // the node found
    {
        bool two_child = ((!m_curr->ltag && nullptr != m_curr->left) && (!m_curr->rtag && nullptr != m_curr->right))
            ? true : false;
        if (two_child) // ��ɾ�ڵ�����������
        {
            tmp = m_curr;
            BSTNode* qq;
            pre_node(m_curr, qq);
            
            int tmp_data = qq->key;
            m_curr = m_curr->left;
            ret = delete_avl(qq->key, val, shorter);
            tmp->key = tmp_data;
            m_curr = tmp;
            if (0 != ret)
            {
                m_curr = nullptr;
                return 1;
            }
            if (shorter)
            {
                switch (m_curr->bf)
                {
                case LH :
                    shorter = true;
                    m_curr->bf = EH;
                    break;
                case EH :
                    shorter = false;
                    m_curr->bf = RH;
                    break;
                case RH :
                    if (m_root == m_curr)
                    {
                        right_balance_for_del(m_curr, shorter);
                        m_root = m_curr;
                        m_root->father = nullptr;
                    }
                    else
                    {
                        curr_father = m_curr->father;
                        if (!curr_father->ltag) 
                        {   // curr�ĸ��ڵ�����ӣ�����ָ��ǰ��������ָ�����ӣ�����m_curr��ȣ���m_currΪ���ڵ������
                            left = m_curr == curr_father->left ? true : false;
                        }
                        else
                        {
                            left = false;
                        }
                        right_balance_for_del(m_curr, shorter);
                        if (left)
                        {
                            curr_father->left = m_curr;
                            curr_father->ltag = false;
                        }
                        else
                        {
                            curr_father->right = m_curr;
                            curr_father->rtag = false;
                        }
                        m_curr->father = curr_father;
                    }
                    break;
                }
            }
        }
        else
        {
            bool flag_delete = delete_node(m_curr);
            if (!flag_delete)
            {
                return 1;
            }
            shorter = true;
        }
        m_b_first = true; // ��ɾ���ڵ�ֻ��һ�����ӣ�������Ҷ��
        m_curr = nullptr;
        return 0;
    }
    else if (e < m_curr->key)
    {
        tmp = m_curr;
        m_curr = m_curr->ltag ? nullptr : m_curr->left;
        ret = delete_avl(e, val, shorter);
        m_curr = tmp;
        if (0 != ret) 
        {
            m_curr = nullptr;
            return 1;
        }
        if (shorter)
        {
             switch (m_curr->bf)
            {
            case LH :
                shorter = true;
                m_curr->bf = EH;
                break;
            case EH :
                shorter = false;
                m_curr->bf = RH;
                break;
            case RH :
                if (m_root == m_curr)
                {
                    right_balance_for_del(m_curr, shorter);
                    m_root = m_curr;
                    m_root->father = nullptr;
                }
                else
                {
                    curr_father = m_curr->father;
                    if (!curr_father->ltag) 
                    {   // curr�ĸ��ڵ�����ӣ�����ָ��ǰ��������ָ�����ӣ�����m_curr��ȣ���m_currΪ���ڵ������
                        left = m_curr == curr_father->left ? true : false;
                    }
                    else
                    {
                        left = false;
                    }
                    right_balance_for_del(m_curr, shorter);
                    if (left)
                    {
                        curr_father->left = m_curr;
                        curr_father->ltag = false;
                    }
                    else
                    {
                        curr_father->right = m_curr;
                        curr_father->rtag = false;
                    }
                    m_curr->father = curr_father;
                }
            }
        }
    }
    else
    {
        tmp = m_curr;
        m_curr = m_curr->rtag ? nullptr : m_curr->right;
        ret = delete_avl(e, val, shorter);
        m_curr = tmp;
        if (0 != ret)
        {
            m_curr = nullptr;
            return 1;
        }
        if (shorter)
        {
            switch (m_curr->bf)
            {
            case LH :
                if (m_root == m_curr)
                {
                    left_balance_for_del(m_curr, shorter);
                    m_root = m_curr;
                    m_root->father = nullptr;
                }
                else
                {
                    curr_father = m_curr->father;
                    if (!curr_father->ltag) 
                    {   // curr�ĸ��ڵ�����ӣ�����ָ��ǰ��������ָ�����ӣ�����m_curr��ȣ���m_currΪ���ڵ������
                        left = m_curr == curr_father->left ? true : false;
                    }
                    else
                    {
                        left = false;
                    }
                    left_balance_for_del(m_curr, shorter);
                    if (left)
                    {
                        curr_father->left = m_curr;
                        curr_father->ltag = false;
                    }
                    else
                    {
                        curr_father->right = m_curr;
                        curr_father->rtag = false;
                    }
                    m_curr->father = curr_father;
                }
                break;
            case EH :
                shorter = false;
                m_curr->bf = LH;
                break;
            case RH :
                m_curr->bf = EH;
                shorter = true;
            }
        }
    }
    m_curr = nullptr;
    m_b_first = true;
    return 0;
}

int myBST::insert_node(int e, void* val)
{
    bool flag;
    return insert_avl(e, val, flag);
}

int myBST::insert_avl(int e, void* val, bool& taller)
{
    int ret = 0;
    bool left = true;
    BSTNode* curr_father;
    BSTNode* A;
    int root_dis;
    int dis;
    if (nullptr == m_root)
    {
        m_curr = m_root = new BSTNode;
        m_curr->val = val;
        m_curr->key = e;
        m_curr->bf = EH;
        taller = true;
        m_b_first = true;
        return 0;
    }
    if (m_b_first)
    {
        m_curr = m_root;
        m_b_first = false;
    }
    if (nullptr == m_curr)
    {
        m_curr = new BSTNode;
        m_curr->val = val;
        m_curr->key = e;
        m_curr->bf = EH;
        taller = true;
        return 0;
    }
    if (e == m_curr->key)
    {
        m_b_first = true;
        return 1;
    }
    else if (e < m_curr->key)
    {
        A = m_curr;
        m_curr = m_curr->ltag ? nullptr : m_curr->left;
        ret = insert_avl(e, val, taller);
        if (((!A->ltag && nullptr == A->left) || A->ltag) && nullptr != m_curr)
        {
            A->left = m_curr;
            A->ltag = false;
            m_curr->father = A;

            // �ڽڵ�A֮ǰ����ڵ�B
            // Bǰ��ΪA��������һԱ�����AnΪAn�ĸ��ڵ���Һ��ӣ�An�ĸ��ڵ�ΪB��ǰ����B�ĺ��ΪA
            // A����������Ϊ��
            // A�ĺ�̲���
            BSTNode* An = A;
            while (nullptr != An->father)
            {   // An�ĸ��״�������������
                if (!An->father->rtag && An == An->father->right)
                {
                    m_curr->ltag = true;
                    m_curr->left = An->father;
                    break;
                }
                else
                {
                    An = An->father;
                }
            }
            m_curr->rtag = true;
            m_curr->right = A;
        }
        m_curr = A;
        if (0 != ret) return 1;
        if (taller) // �������
        {
            if (m_curr->bf <= RH)
            {
                m_curr->bf += LH;
                taller = false;
            }
            else if (m_curr->bf >= LH)
            {
                if (m_root == m_curr)
                {
                    bool is_balance = true;
                    root_dis = 2 * m_curr->key - (m_low + m_high) > 0 ?
                        2 * m_curr->key - (m_low + m_high) : (m_low + m_high) - 2 * m_curr->key;
                    if (NULL != m_curr->left && !m_curr->ltag && LH == m_curr->left->bf)
                    {
                        dis = 2 * m_curr->left->key - (m_low + m_high) > 0 ?
                            2 * m_curr->left->key - (m_low + m_high) : (m_low + m_high) - 2 * m_curr->left->key;
                        if (root_dis < dis)
                        {
                            is_balance = false;
                        }
                    }
                    else if (nullptr != m_curr->left && !m_curr->ltag && 
                        !m_curr->left->rtag && nullptr !=m_curr->left->right && RH == m_curr->left->bf)
                    {
                        dis = 2 * m_curr->left->right->key - (m_low + m_high) > 0 ?
                            2 * m_curr->left->right->key - (m_low + m_high) : (m_low + m_high) - 2 * m_curr->left->right->key;
                        if (root_dis < dis)
                        {
                            is_balance = false;
                        }
                    }
                    else
                    {

                    }
                    if (is_balance)
                    {
                        left_balance(m_curr);
                        m_root = m_curr;
                        m_root->father = nullptr;
                    }
                    else
                    {
                        m_curr->bf += LH;
                    }
                }
                else
                {
                    curr_father = m_curr->father;
                    if (!curr_father->ltag) 
                    {   // curr�ĸ��ڵ�����ӣ�����ָ��ǰ��������ָ�����ӣ�����m_curr��ȣ���m_currΪ���ڵ������
                        left = m_curr == curr_father->left ? true : false;
                    }
                    else
                    {
                        left = false;
                    }
                    left_balance(m_curr);
                    if (left)
                    {
                        curr_father->left = m_curr;
                        curr_father->ltag = false;
                    }
                    else
                    {
                        curr_father->right = m_curr;
                        curr_father->rtag = false;
                    }
                    m_curr->father = curr_father;
                }
                taller = false; 
            }
            else
            {
                m_curr->bf += LH;
                taller = true;
            }
        }     
    }
    else
    {
        A = m_curr;
        m_curr = m_curr->rtag ? nullptr : m_curr->right;
        ret = insert_avl(e, val, taller);
        if (((!A->rtag && nullptr == A->right) || A->rtag) && nullptr != m_curr)
        {
            A->right = m_curr;
            A->rtag = false;

            m_curr->father = A;

            // �ڽڵ�A֮���Ҳ���ڵ�B
            // Bǰ��ΪA��B�ĺ��ΪA��
            // A��ǰ������
            // A����������Ϊ��
            m_curr->ltag = true;
            m_curr->left = A;
            ////////////
            BSTNode* An = A;
            while (nullptr != An->father)
            {   // An�ĸ��״�������������
                if (!An->father->ltag && An == An->father->left)
                {
                    m_curr->rtag = true;
                    m_curr->right = An->father;
                    break;
                }
                else
                {
                    An = An->father;
                }
            }
        }
        m_curr = A;
        if (0 != ret) return 1;
        if (taller)
        {
            if (m_curr->bf < RH || m_curr->bf > LH)
            {
                m_curr->bf += RH;
            }
            else
            {
                switch (m_curr->bf)
                {
                case LH :
                    m_curr->bf = EH;
                    taller = false;
                    break;
                case EH :
                    m_curr->bf = RH;
                    taller = true;
                    break;
                case RH :
                    if (m_root == m_curr)
                    {
                        ////
                        bool is_balance = true;
                        root_dis = 2 * m_curr->key - (m_low + m_high) > 0 ?
                            2 * m_curr->key - (m_low + m_high) : (m_low + m_high) - 2 * m_curr->key;
                        if (nullptr != m_curr->right && !m_curr->rtag && !m_curr->right->ltag
                            && nullptr != m_curr->right->left && LH == m_curr->right->bf)
                        {
                            dis = 2 * m_curr->right->left->key - (m_low + m_high) > 0 ?
                                2 * m_curr->right->left->key - (m_low + m_high) : (m_low + m_high) - 2 * m_curr->right->left->key;
                            if (root_dis < dis)
                            {
                                is_balance = false;
                            }
                        }
                        else if (nullptr != m_curr->right && !m_curr->rtag && RH == m_curr->right->bf)
                        {
                            dis = 2 * m_curr->right->key - (m_low + m_high) > 0 ?
                                2 * m_curr->right->key - (m_low + m_high) : (m_low + m_high) - 2 * m_curr->right->key;
                            if (root_dis < dis)
                            {
                                is_balance = false;
                            }
                        }
                        else
                        {

                        }
                        ////
                        if (is_balance)
                        {
                            right_balance(m_curr);
                            m_root = m_curr;
                            m_root->father = nullptr;
                        }
                        else
                        {
                            m_curr->bf += RH;
                        }
                    }
                    else
                    {
                        curr_father = m_curr->father;
                        if (!curr_father->ltag) 
                        {   // curr�ĸ��ڵ�����ӣ�����ָ��ǰ��������ָ�����ӣ�����m_curr��ȣ���m_currΪ���ڵ������
                            left = m_curr == curr_father->left ? true : false;
                        }
                        else
                        {
                            left = false;
                        }
                        right_balance(m_curr);
                        if (left)
                        {
                            curr_father->left = m_curr;
                            curr_father->rtag = false;
                        }
                        else
                        {
                            curr_father->right = m_curr;
                            curr_father->rtag = false;
                        }
                        m_curr->father = curr_father;
                    }
                    taller = false;
                    break;
                }
            }
        }
    }
    m_b_first = true;
    return 0;
}

// �ҵ��˷��ؽ��ָ�룬�Ҳ�������nullptr������in����Ϊ�������ָ��
BSTNode* myBST::search_add(int e, BSTNode*& in)
{
    if (nullptr == m_root) // not found
    {
        in = m_curr = m_root = new BSTNode;
        m_curr->key = e;
        m_curr->left = nullptr;
        m_curr->right = nullptr;
        m_curr->father = nullptr;
        m_b_first = true;
        return nullptr;
    }
    if (m_b_first)
    {
        m_curr = m_root;
        m_b_first = false;
    }
    if (m_curr->key == e) // found
    {
        m_b_first = true;
        in = nullptr;
        return m_curr;
    }
    else if (e < m_curr->key)
    {
        if (nullptr != m_curr->left)
        {
            m_curr = m_curr->left;
            return search_add(e, in);
        }
        else // not found
        {
            m_curr->left = new BSTNode;
            m_curr->left->key = e;
            m_curr->left->left = nullptr;
            m_curr->left->right = nullptr;
            m_curr->left->father = m_curr;
            in = m_curr->left;
            m_b_first = true;
            return nullptr;
        }
    }
    else
    {
        if (nullptr != m_curr->right)
        {
            m_curr = m_curr->right;
            return search_add(e, in);
        }
        else // not found
        {
            m_curr->right = new BSTNode;
            m_curr->right->key = e;
            m_curr->right->left = nullptr;
            m_curr->right->right = nullptr;
            m_curr->right->father = m_curr;
            in = m_curr->right;
            m_b_first = true;
            return nullptr;
        }
    }
}

int myBST::first_valid(void*& val)
{
    return m_b_next ? search_in_validrange(m_low, m_high, val) : search_in_validrange(m_high, m_low ,val);
}

int myBST::search_in_validrange(int const e, int const compare, void*& val)
{
    int ret = 1;
    BSTNode* tmp;
    if (nullptr == m_root) // not found
    {
        return 1;
    }
    if (m_b_first)
    {
        m_curr = m_root;
        m_b_first = false;
    }
    if (nullptr == m_curr)
    {
        m_b_first = true;
        return 1;
    }
    if (m_curr->key == e) // found
    {
        m_b_first = true;
        m_current = m_curr;
        val = m_curr->val;
        return 0;
    }
    else if (e < m_curr->key) // curr(9), С��9�Ľڵ�e(8)����curr������û���ҵ����������̣�ֱ��ȡcurr
    {
        tmp = m_curr;
        m_curr = m_curr->ltag ? nullptr : m_curr->left;
        ret = search_in_validrange(e, compare, val);
        if (1 == ret) // tmpһ��ΪҶ�ӣ�m_currһ��Ϊ�գ����Ҳ�����ʱ����Ҷ�ӽڵ㣬tmpһ����ǰ����
        {
            if (!m_b_next) // ��Ѱ��
            {
                if (tmp->ltag) // �����ǰ������ǰ��
                {
                    if (compare <= tmp->left->key)
                    {
                        val = tmp->left->val;
                        m_current = tmp->left;
                        return 0;
                    }
                    else
                    {
                        return 2;
                    }
                }
                else // ��ǰ������tmp�Լ�����ǰ�����������һ��tmpΪ����㣬��������������ڵ㣩
                {    // ��Ѱ�ң��ҵ�e�����ߴ�С�ķ���������e����eС��tmp��key��tmp��key����ǰ������˵��tmp��key������������С�㣬����ʧ��
                    return 2;
                }
            }
            else  // ��Ѱ��
            {
                if (compare >= tmp->key)
                {
                    val = tmp->val;
                    m_current = tmp;
                    return 0;
                }
                else
                {
                    return 2;
                }
            }
        }
        return ret;
    }
    else
    {   // �����ҵĽڵ㣬keyֵ����tmp->key
        tmp = m_curr;
        m_curr = m_curr->rtag ? nullptr : m_curr->right;
        ret =  search_in_validrange(e, compare, val);
        if (1 == ret) // tmpһ��ΪҶ�ӣ�m_currһ��Ϊ�գ����Ҳ�����ʱ����Ҷ�ӽڵ㣬tmpһ���к�̣�
        {
            if (m_b_next) // ��Ѱ��
            {
                if (tmp->rtag)
                {
                    if (compare >= tmp->right->key)
                    {
                        val = tmp->right->val;
                        m_current = tmp->right;
                        return 0;
                    }
                    else
                    {
                        return 2;
                    }
                }
                else
                {
                    return 2;
                }
            }
            else // ��Ѱ��
            {
                if (compare <= tmp->key)
                {
                    val = tmp->val;
                    m_current = tmp;
                    return 0;
                }
                else
                {
                    return 2;
                }
            }
        }
        return ret;
    }
}

int myBST::search(int e, void*& val)
{
    if (nullptr == m_root) // not found
    {
        return 1;
    }
    if (m_b_first)
    {
        m_curr = m_root;
        m_b_first = false;
    }
    if (m_curr->key == e) // found
    {
        m_b_first = true;
        val = m_curr->val;
        return 0;
    }
    else if (e < m_curr->key)
    {
        if (!m_curr->ltag && nullptr != m_curr->left)
        {
            m_curr = m_curr->left;
            return search(e, val);
        }
        else // not found
        {
            m_b_first = true;
            return 1;
        }
    }
    else
    {
        if (!m_curr->rtag && nullptr != m_curr->right)
        {
            m_curr = m_curr->right;
            return search(e, val);
        }
        else // not found
        {
            m_b_first = true;
            return 1;
        }
    }
}

bool myBST::delete_node(BSTNode* p)
{
    bool p_is_left = false;
    bool p_is_root = nullptr == p->father ? true : false;
    if (!p_is_root)
    {
        if (!p->father->ltag) 
        {   // p�ĸ��ڵ�����ӣ�����ָ��ǰ��������ָ�����ӣ�����p��ȣ���pΪ���ڵ������
            p_is_left = p == p->father->left ? true : false;
        }
        else
        {
            p_is_left = false;
        }
    }
    else // ɾ�������
    {
        /*m_root = nullptr;*/ // Ŀǰ��֧��ɾ�������
//         return false;
    }
    if (nullptr != p)
    {
        BSTNode* q = p;
        // p��Ҷ�ӣ�����p�Ǹ��ڵ�������
        if ((p->rtag || (nullptr == p->right && !p->rtag )) && (p->ltag || (nullptr == p->left && !p->ltag )))
        {
            if (!p_is_root)
            {
                if (p_is_left)
                {
                    p->father->left = nullptr;
                    p->father->ltag = false;
                    if (p->ltag)
                    {
                        p->father->left = p->left;
                        p->father->ltag = true;
                    }
                }
                else
                {
                    p->father->right = nullptr;
                    p->father->rtag = false;

                    if (p->rtag)
                    {
                        p->father->right = p->right;
                        p->father->rtag = true;
                    }
                }
            }
            else
            {
                m_root = m_curr = nullptr;
            }
        } // p����Ҷ�ӣ�p��������
        else if ((p->rtag || (nullptr == p->right && !p->rtag)))
        {
            p = p->left;
            if (!p_is_root)
            {
                if (p_is_left)// ��ɾ���ڵ����Լ����׵�����
                {
                    q->father->left = p;
                    q->father->ltag = false;
                }
                else
                {
                    q->father->right = p;
                    q->father->rtag = false;
                }
                if (q->rtag) // ���q�к�̣�q�ĺ�̸�ֵ��p�ĺ��
                {
                    p->right = q->right;
                    p->rtag = true;
                }
                p->father = q->father;
            }
            else // ��ɾ���ڵ��Ǹ���㣬���������ڵ�
            {
                m_root = p;
                m_root->left = nullptr;
                m_root->ltag = false;
                m_root->right = nullptr;
                m_root->rtag = false;
                m_root->father = nullptr;
            }
        }
        else if ((p->ltag || (nullptr == p->left && !p->ltag )))
        {
            p = p->right;
            if (!p_is_root)
            {
                if (p_is_left)
                {
                    q->father->left = p;
                    q->father->ltag = false;
                }
                else
                {
                    q->father->right = p;
                    q->father->rtag = false;

                }
                if (q->ltag)
                {
                    p->left = q->left;
                    p->ltag = true;
                }
                p->father = q->father;
            }
            else
            {
                m_root = p;
                m_root->left = nullptr;
                m_root->ltag = false;
                m_root->right = nullptr;
                m_root->rtag = false;
                m_root->father = nullptr;
            }
        }
        else
        {
            BSTNode* s = p->left;
            while (nullptr != s->right) // found the s node ahead of p, use the data of s
            {
                q = s;
                s = s->right;
            }
            // ���ڵ�s��ֵ��ֵ��p��s���û���Һ��ӣ���������ӣ������ӽӵ�q�ڵ���Һ����ϣ���Ϊ�����ӵ�data����q��data��
            // ��Ϊ��������s���������ӣ�s����data����q����data
            p->key = s->key;          
            q == p ? q->left = s->left : q->right = s->left;
            q = s;
            if (m_root == p)
            {
                p->bf = RH;
            }
        }
        delete q;
    }
    return true;
}

// 
// bool myBST::delete_node(int e)
// {
//     void* val;
//     BSTNode* p = search(e, val);
//     bool p_is_left = false;
//     if (nullptr != p->father)
//     {
//         p_is_left = p == p->father->left ? true : false;
//     }
//     if (nullptr != p)
//     {
//         BSTNode* q = p;
// 
//         if (nullptr == p->right && nullptr == p->left)
//         {
//             p_is_left ? p->father->left = nullptr : p->father->right = nullptr;
//         }
//         else if (nullptr == p->right)
//         {
//             p = p->left;
//             p_is_left ? q->father->left = p : q->father->right = p;
//             p->father = q->father;
//         }
//         else if (nullptr == p->left)
//         {
//             p = p->right;
//             p_is_left ? q->father->left = p : q->father->right = p;
//             p->father = q->father;
//         }
//         else
//         {
//             BSTNode* s = p->left;
//             while (nullptr != s->right) // found the node ahead of p
//             {
//                 q = s;
//                 s = s->right;
//             }
//             p->key = s->key;          // assign 
//             q == p ? q->left = s->left : q->right = s->left;
//             q = s;
//         }
//         delete q;
//         return true;
//     }
//     return false;
// }

void myBST::left_rotate(BSTNode*& p)
{   // ������pһ�����Һ���
    BSTNode* q = p->right;
    int is_p_need_assign = 0; // 0��ʾp�ĺ��ӷ����� 1��ʾp���Һ���Ϊ����
    if (q->ltag)  // q������Ϊ������p�Һ���Ӧ��Ϊָ��p�ĺ�̣����Ϊq
    {
        p->right = nullptr;
        is_p_need_assign = 1;
    }
    else// q�����ӷ�����
    {                           
        if (nullptr != q->left) // q�����ӷǿգ�p��������
        {
            p->right = q->left;
            p->rtag = false;
        }
        else // p�Һ��ӣ�p�Һ���Ӧ��Ϊָ��p�ĺ�̣����Ϊq
        {
            p->right = nullptr;
            is_p_need_assign = 1;
        } 
    }
    if (nullptr != q->left && !q->ltag)
    {
        q->left->father = p;
    }
    q->left = p;
    q->ltag = false;
    p->father = q;
    if (is_p_need_assign)
    {
        p->rtag = true;
        p->right = q;
    }
    p = q;
}

void myBST::right_rotate(BSTNode*& p)
{
    BSTNode* q = p->left;
    int is_p_need_assign = 0; // 0��ʾp�ĺ��ӷ����� 1��ʾp������Ϊ����
    if (q->rtag)
    {
        p->left = nullptr;
        is_p_need_assign = 1;
    }
    else
    {
        if (nullptr != q->right)
        {
            p->left = q->right;
            p->ltag = false;
        }
        else
        {
            p->left = nullptr;
            is_p_need_assign = 1;
        }
    }
    if (nullptr != q->right && !q->rtag)
    {
        q->right->father = p;
    }
    q->right = p;
    q->rtag = false;
    p->father = q;
    if (is_p_need_assign)
    {
        p->ltag = true;
        p->left = q;
    }
    p = q;
}

void myBST::print_inorder()
{
    std::cout << "in order print start: " << std::endl;
    inorder(m_root);
//     std::cout << std::endl;
}

void myBST::print_preorder()
{
    preorder(m_root);
    std::cout << std::endl;
}

void myBST::print_levelorder()
{
    std::cout << "level order print start: " << std::endl;
    levelorder(m_root);
//     std::cout << std::endl;
}

void myBST::print_inorder_no_bf()
{
    std::cout << "in order print no bf start: " << std::endl;
    inorder_no_bf(m_root);
//     std::cout << std::endl;
}

void myBST::print_inorder_valid_range()
{
    std::cout << "in order print no bf valid range: [" << m_low << ", " << m_high << "]" << std::endl;
    inorder_valid_range(m_root);
//     std::cout << std::endl;
}

void myBST::print_info()
{
    //void* val;
    if (m_b_next)
    {
        std::cout << "this is a sale tray:" << std::endl;
    }
    else
    {
        std::cout << "this is a buy tray:" << std::endl;;
    }
    print_levelorder();
    print_inorder_no_bf();
    if (!m_log_str.empty())
    {
        std::cout << m_log_str << std::endl;
        m_log_str.clear();
    }
    m_log_str.clear();
    print_inorder_valid_range();
    if (!m_log_str.empty())
    {
        std::cout << m_log_str << std::endl;
        m_log_str.clear();
    }
    m_log_str.clear();
}

int myBST::first(void*& val)
{
    BSTNode* p;
    int ret = m_b_next ? first(p) : end(p);
    if (0 == ret)
    {
        val = p->val;
        m_current = p;
    }
    return ret;
}

int myBST::end(void*& val)
{
    BSTNode* p;
    int ret = m_b_next ? end(p) : first(p);
    if (0 == ret)
    {
        val = p->val;
        m_current = p;
    }
    return ret;
}

int myBST::first_buy_valid(int const price,  int const compare_price, void*& val)
{
    return 1;
}

int myBST::first_sale_valid(int const price, int const compare_price, void*& val)
{
       return 1;
}

int myBST::pre(void*& val)
{
    if (nullptr == m_current)
    {
        return 1;
    }
    BSTNode* q;
    int ret = m_b_next ? pre_node(m_current, q) : next_node(m_current, q);
    if (0 == ret)
    {
        val = q->val;
        m_current = q;
    }
    return ret;
}

int myBST::pre_valid(void*& val, int const compare)
{
    if (nullptr == m_current)
    {
        return 1;
    }
    BSTNode* q;
    int ret = m_b_next ? pre_node(m_current, q) : next_node(m_current, q);
    if (0 == ret)
    {
//         if (m_b_next)
//         {
//             q->key > compare;
//             return 1;
//         }
//         else
//         {
// 
//         }
        val = q->val;
        m_current = q;
    }
    return ret;
}

int myBST::next(void*& val)
{
    if (nullptr == m_current)
    {
        return 1;
    } 
    BSTNode* q;
    int ret = m_b_next ? next_node(m_current, q) : pre_node(m_current, q);
    if (0 == ret)
    {
        val = q->val;
        m_current = q;
    }
    return ret;
}

int myBST::next_valid(void*& val, int const compare)
{
    if (nullptr == m_current)
    {
        return 1;
    } 
    BSTNode* q;
    int ret = m_b_next ? next_node(m_current, q) : pre_node(m_current, q);
    if (0 == ret)
    {
        if ((m_b_next && q->key > compare) || (!m_b_next && q->key < compare))
        {
            return 1;
        }
        val = q->val;
        m_current = q;
    }
    return ret;
}

int myBST::next_valid(void*& val)
{
    if (nullptr == m_current)
    {
        return 1;
    } 
    BSTNode* q;
    int ret = m_b_next ? next_node(m_current, q) : pre_node(m_current, q);
    if (0 == ret)
    {
        if ((m_b_next && q->key > m_high) || (!m_b_next && q->key < m_low))
        {
            return 1;
        }
        val = q->val;
        m_current = q;
    }
    return ret;
}

int myBST::first(BSTNode*& val)
{
    BSTNode* p = nullptr;
    val = nullptr;
    if (nullptr == m_root)
    {
        return 1;
    }

    p = m_root;
    while (nullptr != p->left && !p->ltag)
    {
        p = p->left;
    }

    val = p;
    return 0; 
}

int myBST::end(BSTNode*& val)
{
    BSTNode* p = nullptr;
    val = nullptr;
    if (nullptr == m_root)
    {
        return 1;
    }

    p = m_root;
    while (nullptr != p->right && !p->rtag)
    {
        p = p->right;
    }

    val = p;
    return 0; 
}


int myBST::pre_node(const BSTNode* p, BSTNode*& q)
{
    q = nullptr;
    if (p->ltag) 
    {
        q = p->left;
    }
    else
    {
        if (nullptr == p->left) // û����������û��ǰ��
        {
            q = nullptr;
        }
        else
        {
            q = p->left;
            while (nullptr != q->right && !q->rtag) // found the s node ahead of p, use the data of s
            {
                q = q->rtag ? nullptr : q->right;
            }
            // ���ڵ�s��ֵ��ֵ��p��s���û���Һ��ӣ���������ӣ������ӽӵ�q�ڵ���Һ����ϣ���Ϊ�����ӵ�data����q��data��
            // ��Ϊ��������s���������ӣ�s����data����q����data
        }
    }
    return nullptr == q ? 1 : 0;
}

int myBST::next_node(const BSTNode* p, BSTNode*& q)
{
    q = nullptr;
    if (p->rtag) // �Һ���������
    {
        q = p->right;
    }
    else
    {
        if (nullptr == p->right) // ���������������ʣ��Һ��Ӳ����������Һ������ǿյģ���ô����ڵ�û�к��
        {
            q = nullptr;
        }
        else // ����������
        {
            q = p->right;
            while (nullptr != q->left && !q->ltag) // found the s node ahead of p, use the data of s
            {
                q = q->ltag ? nullptr : q->left;
            }
        }
    }

    return q == nullptr ? 1 : 0 ;
}


void myBST::print_by_pre()
{
    BSTNode* p;
    BSTNode* q;
    end(p);
    while (nullptr != p)
    {
        if (EH != p->bf)
        {
            std::cout << p->key;
            std::cout << "(bf=" << p->bf << ") " ;
        }
        else
        {
            std::cout << p->key << " ";
        }
        pre_node(p, q);
        p = q;
    }
    std::cout << std::endl;
}

void myBST::print_by_next()
{
     BSTNode* p;
     BSTNode* q;
     first(p);
     while (nullptr != p)
     {
         if (EH != p->bf)
         {
             std::cout << p->key;
             std::cout << "(bf=" << p->bf << ") " ;
         }
         else
         {
             std::cout << p->key << " ";
         }
         next_node(p, q);
         p = q;
     }
     std::cout << std::endl;
}

void myBST::inorder(BSTNode* p)
{
    char tmp[1024];
    memset(tmp, 0, 1024);
    if (nullptr != p)
    {
        if ((nullptr != p->left && !p->ltag))
        {
            inorder(p->left);
        }
        if (EH != p->bf)
        {
            sprintf_s(tmp, "%d(bf=%d) ", p->key, p->bf);
        }
        else
        {
            sprintf_s(tmp, "%d ", p->key);
        }
        m_log_str += tmp;
        if (nullptr != p->right && !p->rtag)
        {
            inorder(p->right);
        }
    }
}

void myBST::preorder(BSTNode* p)
{
    if (nullptr != p)
    {
        if (EH != p->bf)
        {
            std::cout << p->key;
            std::cout << "(bf=" << p->bf << ") " ;
        }
        else
        {
            std::cout << p->key << " ";
        }
        if ((nullptr != p->left && !p->ltag))
        {
            preorder(p->left);
        } 
        if (nullptr != p->right && !p->rtag)
        {
            preorder(p->right);
        }
    }
}

void print_space(int i)
{
    switch (i)
    {
    case 0:
        std::cout << "    ";
        break;
    case 1:
        std::cout << "  ";
        break;
    case 2:
        std::cout << "   ";
        break;
    case 3:
    case 4:
    case 5:
    case 6:
        std::cout << " ";
        break;
    }
}
void myBST::levelorder(BSTNode* p)
{
    std::vector<BSTNode*> vec; // ��������ʹ��STL �е�vector���������飬�����õ��䶯̬��չ������
    if (nullptr == m_root)
    {
        return;
    }
    vec.push_back(m_root);
    int cur = 0;
    int last = 1;
    BSTNode k;
    k.key = 0;
    char tmp[256];
    memset(tmp, 0, 256 * sizeof(char));
    std::string tmp_str_sum;
    while(static_cast<std::vector<BSTNode*>::size_type>(cur) < vec.size())
    {
        last = static_cast<int>(vec.size()); // �µ�һ�з��ʿ�ʼ�����¶�λlast�ڵ�ǰ�����һ���ڵ����һ��λ��
        while(cur < last)
        {
            if (0 == vec[cur]->bf)
            {
                sprintf_s(tmp, "%d ", vec[cur]->key);
            } 
            else if (1 == vec[cur]->bf)
            {
                sprintf_s(tmp, "%d(%s) ", vec[cur]->key, "L");
            }
            else
            {
                sprintf_s(tmp, "%d(%s) ", vec[cur]->key, "R");
            }
            tmp_str_sum += tmp;
            if(!vec[cur]->ltag && vec[cur] ->left) // ��ǰ���ʽڵ����ڵ㲻Ϊ����ѹ��
            {
                vec.push_back(vec[cur]->left);
            }
            if(!vec[cur]->rtag && vec[cur] ->right) // ��ǰ���ʽڵ���ҽڵ㲻Ϊ����ѹ�룬ע�����ҽڵ�ķ���˳���ܵߵ�
            {
                vec.push_back(vec[cur] ->right);
            }
            cur++;
        }
        std::cout << tmp_str_sum << std::endl;
        tmp_str_sum.clear();
    }
}

void myBST::inorder_no_bf(BSTNode* p)
{
    char tmp[1024];
    memset(tmp, 0, 1024);
    if (nullptr != p)
    {
        if ((nullptr != p->left && !p->ltag))
        {
            inorder_no_bf(p->left);
        }
        //std::cout << p->key << " ";
        //DEBUG(TS_DEBUG_GETMEMORYINFO, "%d ", p->key);
        sprintf_s(tmp, "%d ", p->key);
        m_log_str += tmp;
        if (nullptr != p->right && !p->rtag)
        {
            inorder_no_bf(p->right);
        }
    }
}

void myBST::inorder_valid_range(BSTNode* p)
{
    char tmp[1024];
    memset(tmp, 0, 1024);
    if (nullptr != p)
    {
        if ((nullptr != p->left && !p->ltag))
        {
            inorder_valid_range(p->left);
        }
        if (p->key >= m_low && p->key <= m_high)
        {
            sprintf_s(tmp, "%d ", p->key);
            m_log_str += tmp;
            //std::cout << p->key << " ";
            //DEBUG(TS_DEBUG_GETMEMORYINFO, "%d ", p->key);
        }
        if (nullptr != p->right && !p->rtag)
        {
            inorder_valid_range(p->right);
        }
    }
}
