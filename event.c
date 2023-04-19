/// @file event.c
/// @brief 事件管理
AAAAAAAAAAAAAAAAAAA
#include "event_def.h"
#include "util_interface.h"
#include "event_interface.h"

///保存需要执行操作的消息缓存，每一位表示一个消息
static u16 event_data[EVENT_INDEX_MAX] =
{ 0 };

/**
 * @fn void event_create_by_publisher(EVENT_E)
 * @brief 事件生产者设置事件
 *
 * @param event_index 事件序号
 */
void event_create_by_publisher(EVENT_E event_index)
{
    event_data[event_index] = 0xffff;
    printf("evt:%d\r\n", event_index);
}

/**
 * @fn U8 event_get_from_consumer(EVENT_E, EVENT_CONSUMER_INDEX_E)
 * @brief 事件消费者获取事件
 *
 * @param event_index 事件序号
 * @param client_index 消费者序号
 * @return 1：获取到事件，0：获取不到事件
 */
U8 event_get_from_consumer(EVENT_E event_index, EVENT_CONSUMER_INDEX_E client_index)
{
    U8 have_event = GET_BIT(event_data[event_index], client_index);

    if (have_event == 1)
    {
        DATA_CLEAR_BIT(event_data[event_index], client_index);
    }
    return have_event;
}

