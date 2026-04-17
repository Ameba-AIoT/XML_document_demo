* [English Version](./README.md)

### Ameba RTL8721Dx 系列 SoC XML 示例（FreeRTOS）

🚀 本示例基于 **Ameba RTL8721Dx 系列 SoC**，演示如何在 FreeRTOS 上使用轻量级 XML（可扩展标记语言）库来创建与解析 XML 文档。

- 📎 开发板购买链接：  
  - [🛒 淘宝](https://item.taobao.com/item.htm?id=904981157046)  
  - [📦 Amazon](https://www.amazon.com/-/zh/dp/B0FB33DT2C/)  
- 📄 [芯片与模组详情](https://aiot.realmcu.com/zh/module/rtl8721dx.html)

---

### 示例功能

✅ 在设备端**构建一个结构化 XML 文档**  
✅ 在本地**解析该 XML 文档**，并读取指定节点与属性值  

---

### 快速开始

1️⃣ **选择SDK**  
   - 设置`env.sh`（`env.bat`）路径：`source {sdk}/env.sh`  
   - 将`{sdk}`替换为[ameba-rtos SDK](https://github.com/Ameba-AIoT/ameba-rtos)根目录中`env.sh`的绝对路径。如果SDK路径没有改变，此步骤仅需执行一次。

   ⚡ **注意**：本示例仅支持 SDK 版本 **≥ v1.2**

2️⃣ **编译**  
   - 在当前工程目录下执行：  
     ```bash
     source env.sh
     ameba.py build -p
     ```

3️⃣ **烧录固件**
   >请将命令中的 `COMx` 替换为实际串口号（例如 `COM5`）
   ```bash
   ameba.py flash --p COMx --image km4_boot_all.bin 0x08000000 0x8014000 --image km0_km4_app.bin 0x08014000 0x8200000
   ```
   ⚡ **Note**: 项目目录中提供的预编译bin文件也可以用如下方式烧录：
   ```bash
   ameba.py flash --p COMx --image ../km4_boot_all.bin 0x08000000 0x8014000 --image ../km0_km4_app.bin 0x08014000 0x8200000
   ```

4️⃣ **打开串口监视**  
   - `ameba.py monitor --port COMx --b 1500000`

---

5️⃣ **观察日志输出** 📜  

上电并启动后，可在串口日志中看到启动信息、XML 文档生成结果及解析结果。

---

### 日志输出示例

```text
[MONITOR] 2026-04-02 17:38:47.162 #
[MONITOR] 2026-04-02 17:38:50.827 #ROM:[V1.1]
[MONITOR] 2026-04-02 17:38:50.827 FLASH RATE:1, Pinmux:1
[MONITOR] 2026-04-02 17:38:50.827 IMG1(OTA1) VALID, ret: 0
[MONITOR] 2026-04-02 17:38:50.827 IMG1 ENTRY[f800779:0]
[MONITOR] 2026-04-02 17:38:50.827 [BOOT-I] KM4 BOOT REASON 0: Initial Power on
[MONITOR] 2026-04-02 17:38:50.827 [BOOT-I] KM4 CPU CLK: 240000000 Hz
[MONITOR] 2026-04-02 17:38:50.827 [BOOT-I] KM0 CPU CLK: 96000000 Hz
[MONITOR] 2026-04-02 17:38:50.827 [BOOT-I] PSRAM Ctrl CLK: 240000000 Hz
[MONITOR] 2026-04-02 17:38:50.837 [BOOT-I] IMG1 ENTER MSP:[30009FDC]
[MONITOR] 2026-04-02 17:38:50.837 [BOOT-I] Build Time: Apr  1 2026 18:25:00
[MONITOR] 2026-04-02 17:38:50.837 [BOOT-I] IMG1 SECURE STATE: 1
[MONITOR] 2026-04-02 17:38:50.837 [FLASH-I] FLASH CLK: 80000000 Hz
[MONITOR] 2026-04-02 17:38:50.837 [FLASH-I] Flash ID: 85-20-16 (Capacity: 32M-bit)
[MONITOR] 2026-04-02 17:38:50.837 [FLASH-I] Flash Read 4IO
[MONITOR] 2026-04-02 17:38:50.837 [FLASH-I] FLASH HandShake[0x2 OK]
[MONITOR] 2026-04-02 17:38:50.847 [BOOT-I] KM0 XIP IMG[0c000000:8400]
[MONITOR] 2026-04-02 17:38:50.847 [BOOT-I] KM0 SRAM[20068000:860]
[MONITOR] 2026-04-02 17:38:50.847 [BOOT-I] KM0 PSRAM[0c008c60:20]
[MONITOR] 2026-04-02 17:38:50.847 [BOOT-I] KM0 ENTRY[20004d00:60]
[MONITOR] 2026-04-02 17:38:50.847 [BOOT-I] KM4 XIP IMG[0e000000:19fa0]
[MONITOR] 2026-04-02 17:38:50.847 [BOOT-I] KM4 SRAM[2000b000:460]
[MONITOR] 2026-04-02 17:38:50.847 [BOOT-I] KM4 PSRAM[0e01a400:20]
[MONITOR] 2026-04-02 17:38:50.847 [BOOT-I] KM4 ENTRY[20004d80:40]
[MONITOR] 2026-04-02 17:38:50.847 [BOOT-I] IMG2 BOOT from OTA 1, Version: 1.1
[MONITOR] 2026-04-02 17:38:50.847 [BOOT-I] Image2Entry @ 0xe009079 ...
[MONITOR] 2026-04-02 17:38:50.847 [APP-I] [KM4 APP START LOCKS-I]
[MONITOR] 2026-04-02 17:38:50.847 [APP-I KM0 ini] VTOR: t_retarg30007000et_locks, VTOR_NS:300070
[MONITOR] 2026-04-02 17:38:50.847 00
[MONITOR] 2026-04-02 17:38:50.847 [APP-I] VTOR: 30007000, VTOR_NS:30007000
[MONITOR] 2026-04-02 17:38:50.847 [APP-I] IMG2 SECURE STATE[MAIN-I: 1
[MONITOR] 2026-04-02 17:38:50.847 ] IWDG refresh on!
[MONITOR] 2026-04-02 17:38:50.847 [MAIN-I] KM0 OS START
[MONITOR] 2026-04-02 17:38:50.847 [CLK-I] [CAL4M]: delta:1 target:320 PPM: 3125 PPM_Limit:30000
[MONITOR] 2026-04-02 17:38:50.857 [CLK-I] [CAL131K]: delta:13 target:2441 PPM: 5325 PPM_Limit:30000
[MONITOR] 2026-04-02 17:38:50.857 [LOCKS-I] KM4 init_retarget_locks
[MONITOR] 2026-04-02 17:38:50.857 [APP-I] BOR arises when supply voltage decreases under 2.57V and recovers above 2.7V.
[MONITOR] 2026-04-02 17:38:50.857 [MAIN-I] KM4 MAIN
[MONITOR] 2026-04-02 17:38:50.857 [VER-I] AMEBA-RTOS SDK VERSION: 1.2.0
[MONITOR] 2026-04-02 17:38:50.857 [MAIN-I] File System Init Success
[MONITOR] 2026-04-02 17:38:50.867 [app_main-I] example_xml_thread creat……
[MONITOR] 2026-04-02 17:38:50.867 [MAIN-I] KM4 START SCHEDULER

[MONITOR] 2026-04-02 17:38:50.867
[MONITOR] 2026-04-02 17:38:50.867 Example: XML
[MONITOR] 2026-04-02 17:38:50.867
[MONITOR] 2026-04-02 17:38:50.867 <Home:Light xmlns:Home="http://www.home.com" xmlns="http://www.device.com" fw_ver="1.0.0"><Power>on</Power><Color><Red>255</Red><Green>255</Green><Blue>255</Blue></Color></Home:Light>
[MONITOR] 2026-04-02 17:38:50.867
[MONITOR] 2026-04-02 17:38:50.867 <?xml version="1.0"?>
[MONITOR] 2026-04-02 17:38:50.867 <Home:Light xmlns:Home="http://www.home.com" xmlns="http://www.device.com" fw_ver="1.0.0">
[MONITOR] 2026-04-02 17:38:50.867     <Power>on</Power>
[MONITOR] 2026-04-02 17:38:50.867     <Color>
[MONITOR] 2026-04-02 17:38:50.867         <Red>255</Red>
[MONITOR] 2026-04-02 17:38:50.867         <Green>255</Green>
[MONITOR] 2026-04-02 17:38:50.867         <Blue>255</Blue>
[MONITOR] 2026-04-02 17:38:50.867     </Color>
[MONITOR] 2026-04-02 17:38:50.867 </Home:Light>
[MONITOR] 2026-04-02 17:38:50.867
[MONITOR] 2026-04-02 17:38:50.867 <Home:Sensor>
[MONITOR] 2026-04-02 17:38:50.867     <Thermostat>
[MONITOR] 2026-04-02 17:38:50.868         <Mode>auto</Mode>
[MONITOR] 2026-04-02 17:38:50.868         <Temperature unit="celsius">25.5</Temperature>
[MONITOR] 2026-04-02 17:38:50.868     </Thermostat>
[MONITOR] 2026-04-02 17:38:50.868 </Home:Sensor>
[MONITOR] 2026-04-02 17:38:50.868
[MONITOR] 2026-04-02 17:38:50.868 Find 1 element by /Home:Sensor/Thermostat/Temperature
[MONITOR] 2026-04-02 17:38:50.868 Temperature[0] is 25.5
[MONITOR] 2026-04-02 17:38:50.868 Unit is "celsius"
...
```