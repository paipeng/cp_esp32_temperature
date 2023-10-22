
#include "public.h"
#include <DallasTemperature.h>

#define ONE_WIRE_BUS    13 //1-wire数据总线连接
OneWire oneWire(ONE_WIRE_BUS); //声明
DallasTemperature sensors(&oneWire); //声明

void setup(){
  Serial.begin(115200);
  sensors.begin();
}

void loop(){
  Serial.println("发起温度转换");
  sensors.requestTemperatures(); //向总线上所有设备发送温度转换请求，默认情况下该方法会阻塞
  Serial.println("温度转换完成");

  float tempC = sensors.getTempCByIndex(0); //获取索引号0的传感器摄氏温度数据
  if (tempC != DEVICE_DISCONNECTED_C) //如果获取到的温度正常
  {
    Serial.print("当前温度是： ");
    Serial.print(tempC);
    Serial.println(" ℃\n");
  }
  delay(2000);
}
