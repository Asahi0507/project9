// -*- C++ -*-
/*!
 * @file  SendToSpeakerTest.cpp
 * @brief 受け取った文字列に即した音声ファイルをスピーカーに送る
 * @date $Date$
 *
 * $Id$
 */

#include "SendToSpeakerTest.h"

// Module specification
// <rtc-template block="module_spec">
static const char* sendtospeaker_spec[] =
  {
    "implementation_id", "SendToSpeakerTest",
    "type_name",         "SendToSpeakerTest",
    "description",       "受け取った文字列に即した音声ファイルをスピーカーに送る",
    "version",           "1.0.0",
    "vendor",            "Tae",
    "category",          "send",
    "activity_type",     "EVENTDRIVEN",
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
SendToSpeakerTest::SendToSpeakerTest(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_MusicIn("Music", m_Music),
    m_SendOut("Send", m_Send)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
SendToSpeakerTest::~SendToSpeakerTest()
{
}



RTC::ReturnCode_t SendToSpeakerTest::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("Send", m_SendIn);
  
  // Set OutPort buffer
  addOutPort("Music", m_MusicOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t SendToSpeakerTest::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SendToSpeakerTest::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SendToSpeakerTest::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t SendToSpeakerTest::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t SendToSpeakerTest::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t SendToSpeakerTest::onExecute(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t SendToSpeakerTest::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t SendToSpeakerTest::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t SendToSpeakerTest::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t SendToSpeakerTest::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SendToSpeakerTest::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void SendToSpeakerTestInit(RTC::Manager* manager)
  {
    coil::Properties profile(sendtospeaker_spec);
    manager->registerFactory(profile,
                             RTC::Create<SendToSpeakerTest>,
                             RTC::Delete<SendToSpeakerTest>);
  }
  
};


