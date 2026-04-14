#include "XML_demo.h" 

void app_example(void)
{  
   
    RTK_LOGI(TAG, "example_xml_thread creat……\r\n");   
    if (rtos_task_create(NULL, "example_xml_thread", (rtos_task_t) example_xml_thread, NULL, 1024 * 4, 1) != RTK_SUCCESS) 
    {
        RTK_LOGE(TAG, "\n\r%s rtos_task_create(init_thread) failed", __FUNCTION__);
    }
    
}
