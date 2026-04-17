
* [中文版](./README_CN.md)

### XML Document Example for Ameba RTL8721Dx Series SoC (FreeRTOS)

🚀 This example is based on the **Ameba RTL8721Dx series SoC** and demonstrates how to use a lightweight XML library on FreeRTOS to create and parse XML documents on the device.

- 📎 Development board purchase links:  
  - [🛒 Taobao](https://item.taobao.com/item.htm?id=904981157046)  
  - [📦 Amazon](https://www.amazon.com/-/zh/dp/B0FB33DT2C/)  
- 📄 [Chip & module information](https://aiot.realmcu.com/zh/module/rtl8721dx.html)

---

### Features

✅ Create a structured XML document on the device  
✅ Parse the XML document locally and read specific elements and attributes  

---

### Getting Started

1️⃣ **Select SDK**  
   - Set the path for `env.sh` (`env.bat`): `source {sdk}/env.sh`  
   - Replace `{sdk}` with the absolute path to `env.sh` in the root directory of the [ameba-rtos SDK](https://github.com/Ameba-AIoT/ameba-rtos). This step only needs to be performed once if the SDK path remains unchanged.

2️⃣ **Build**  
   - Execute the following in the demo example directory:  
     ```bash
     source env.sh
     ameba.py build -p
     ```

3️⃣ **Burning the Firmware**  
   > Replace `COMx` with your actual serial port (for example, `COM5`).

```bash
ameba.py flash --p COMx --image km4_boot_all.bin 0x08000000 0x8014000 --image km0_km4_app.bin 0x08014000 0x8200000
```

 ⚡ **Note**: Precompiled bin files are also provided in the project directory and can be flashed as follows:

```bash
ameba.py flash --p COMx --image ../km4_boot_all.bin 0x08000000 0x8014000 --image ../km0_km4_app.bin 0x08014000 0x8200000
```

4️⃣ **Monitor**  
   - `ameba.py monitor --port COMx --b 1500000`

5️⃣ **Check the Log Output** 📜  

After power-up and boot, you should see the boot messages, the generated XML content, and the XML parsing results in the serial log.

---

### Log Output Example

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
