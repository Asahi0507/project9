// -*- C++ -*-
/*!
 * @file  SelectMusicTest.cpp
 * @brief ModuleDescription
 * @date $Date$
 *
 * @author AsahiNiikura<cy17248@shibaura-it.ac.jp>
 *
 * $Id$
 */

#include "SelectMusicTest.h"

// Module specification
// <rtc-template block="module_spec">
static const char* selectmusic_spec[] =
  {
    "implementation_id", "SelectMusicTest",
    "type_name",         "SelectMusicTest",
    "description",       "ModuleDescription",
    "version",           "1.0.0",
    "vendor",            "AsahiNiikura",
    "category",          "RockRock",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    // Configuration variables
    "conf.default.Instrument", ""guitar"",

    // Widget
    "conf.__widget__.Instrument", "radio",
    // Constraints
    "conf.__constraints__.Instrument", "("guitar","base","drum")",

    "conf.__type__.Instrument", "string",

    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
SelectMusicTest::SelectMusicTest(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_XYZIn("XYZ", m_XYZ),
    m_FilenameOut("Filename", m_Filename)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
SelectMusicTest::~SelectMusicTest()
{
}



RTC::ReturnCode_t SelectMusicTest::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("Filename", m_FilenameIn);
  
  // Set OutPort buffer
  addOutPort("XYZ", m_XYZOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // Bind variables and configuration variable
  bindParameter("Instrument", m_Inst, ""guitar"");
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t SelectMusicTest::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SelectMusicTest::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SelectMusicTest::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SelectMusicTest::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SelectMusicTest::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*!
 * 受け取ったデータに応じて流す音楽ファイルのファイル名を出力する
 * コンフィグで楽器を選択する(guitar,base,dram)
 */

RTC::ReturnCode_t SelectMusicTest::onExecute(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}

/*!
 * エラーの時メッセージを出力し停止する
 */

RTC::ReturnCode_t SelectMusicTest::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t SelectMusicTest::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SelectMusicTest::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SelectMusicTest::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SelectMusicTest::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void SelectMusicTestInit(RTC::Manager* manager)
  {
    coil::Properties profile(selectmusic_spec);
    manager->registerFactory(profile,
                             RTC::Create<SelectMusicTest>,
                             RTC::Delete<SelectMusicTest>);
  }
  
};


