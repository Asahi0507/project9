// -*- C++ -*-
/*!
 * @file  SendToSpeaker.cpp
 * @brief 受け取った文字列に即した音声ファイルをスピーカーに送る
 * @date $Date$
 * 
 * @author Tae MITSUFUJI
 * cy17261@shibaura-it.ac.jp
 * $Id$
 */

#include "SendToSpeaker.h"
#pragma comment(lib,"winmm.lib")
#include <string>
#include <stdlib.h>
#include <mmsystem.h>
#include <sys/types.h>



// Module specification
// <rtc-template block="module_spec">
static const char* sendtospeaker_spec[] =
  {
    "implementation_id", "SendToSpeaker",
    "type_name",         "SendToSpeaker",
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

SendToSpeaker::SendToSpeaker(RTC::Manager* manager)
    // <rtc-template block="initializer">
	: RTC::DataFlowComponentBase(manager),
	m_MusicIn("Music", m_Music)

	// </rtc-template>
{
}
/*!
 * @brief destructor
 */
SendToSpeaker::~SendToSpeaker()
{
}


/*
 * ポート使用の宣言
 */
RTC::ReturnCode_t SendToSpeaker::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("Music", m_MusicIn);
  
  // Set OutPort buffer

  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t SendToSpeaker::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SendToSpeaker::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SendToSpeaker::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t SendToSpeaker::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t SendToSpeaker::onDeactivated(RTC::UniqueId ec_id){
	PlaySound(NULL, NULL, SND_ASYNC);
	return RTC::RTC_OK;
}

/*!
 * wavファイルを非同期処理で再生
 */
RTC::ReturnCode_t SendToSpeaker::onExecute(RTC::UniqueId ec_id)
{
	if (m_MusicIn.isNew()) {	//新しいデータが来た時
		m_MusicIn.read();
		std::cout << m_Music.data << std::endl;
		std::string newName = m_Music.data;
		if (newName == "guitar_c.wav") {
			PlaySound("guitar_c.wav" , NULL, SND_FILENAME | SND_ASYNC);	//ギターC音声ファイル呼び出し
		}else if (newName == "guitar_g.wav") {
			PlaySound("guitar_g.wav", NULL, SND_FILENAME | SND_ASYNC);	//ギターG音声ファイル呼び出し
		}else if (newName == "guitar_e.wav") {
			PlaySound("guitar_e.wav", NULL, SND_FILENAME | SND_ASYNC);	//ギターE音声ファイル呼び出し
		}else if (newName == "base_c.wav") {
			PlaySound("base_c.wav", NULL, SND_FILENAME | SND_ASYNC);	//ベースC音声ファイル呼び出し
		}else if (newName == "base_g.wav") {
			PlaySound("base_g.wav", NULL, SND_FILENAME | SND_ASYNC);	//ベースG音声ファイル呼び出し
		}else if (newName == "base_e.wav") {
			PlaySound("base_e.wav", NULL, SND_FILENAME | SND_ASYNC);	//ベースE音声ファイル呼び出し
		}else if (newName == "drum_cynbal.wav") {
			PlaySound("drum_cynbal.wav", NULL, SND_FILENAME | SND_ASYNC);	//ドラム1音声ファイル呼び出し
		}else if (newName == "drum_snare.wav") {
			PlaySound("drum_snare.wav", NULL, SND_FILENAME | SND_ASYNC);	//ドラム2音声ファイル呼び出し
		}else if (newName == "drum_bass.wav") {
			PlaySound("drum_bass.wav", NULL, SND_FILENAME | SND_ASYNC);	//ドラム3音声ファイル呼び出し
		}
		else {}
	}
	return RTC::RTC_OK;
}


RTC::ReturnCode_t SendToSpeaker::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t SendToSpeaker::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t SendToSpeaker::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t SendToSpeaker::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SendToSpeaker::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void SendToSpeakerInit(RTC::Manager* manager)
  {
    coil::Properties profile(sendtospeaker_spec);
    manager->registerFactory(profile,
                             RTC::Create<SendToSpeaker>,
                             RTC::Delete<SendToSpeaker>);
  }
  
};