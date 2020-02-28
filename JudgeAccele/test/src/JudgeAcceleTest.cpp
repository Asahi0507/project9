// -*- C++ -*-
/*!
 * @file  JudgeAcceleTest.cpp
 * @brief 受け取った加速度センサーのデータ型を変換して出力する
 * @date $Date$
 *
 * @author Tae MITSUFUJI<cy17261@shibaura-it.ac.jp>
 *
 * $Id$
 */

#include "JudgeAcceleTest.h"

// Module specification
// <rtc-template block="module_spec">
static const char* judgeaccele_spec[] =
  {
    "implementation_id", "JudgeAcceleTest",
    "type_name",         "JudgeAcceleTest",
    "description",       "受け取った加速度センサーのデータ型を変換して出力する",
    "version",           "1.0.0",
    "vendor",            "TaeMITSUFUJI",
    "category",          "accept",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
JudgeAcceleTest::JudgeAcceleTest(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_HotmockAcceleIn("HotmockAccele", m_HotmockAccele),
    m_AcceleNumberOut("AcceleNumber", m_AcceleNumber)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
JudgeAcceleTest::~JudgeAcceleTest()
{
}



RTC::ReturnCode_t JudgeAcceleTest::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("AcceleNumber", m_AcceleNumberIn);
  
  // Set OutPort buffer
  addOutPort("HotmockAccele", m_HotmockAcceleOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t JudgeAcceleTest::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t JudgeAcceleTest::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t JudgeAcceleTest::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t JudgeAcceleTest::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t JudgeAcceleTest::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t JudgeAcceleTest::onExecute(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t JudgeAcceleTest::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t JudgeAcceleTest::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t JudgeAcceleTest::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t JudgeAcceleTest::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t JudgeAcceleTest::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void JudgeAcceleTestInit(RTC::Manager* manager)
  {
    coil::Properties profile(judgeaccele_spec);
    manager->registerFactory(profile,
                             RTC::Create<JudgeAcceleTest>,
                             RTC::Delete<JudgeAcceleTest>);
  }
  
};


