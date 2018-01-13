﻿/*
 * MIT License
 *
 * Copyright (c) 2016 xiongziliang <771730766@qq.com>
 *
 * This file is part of ZLMediaKit(https://github.com/xiongziliang/ZLMediaKit).
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef SRC_MEDIAFILE_MEDIARECORDER_H_
#define SRC_MEDIAFILE_MEDIARECORDER_H_

#include <memory>
#include "Player/PlayerBase.h"

#ifdef  ENABLE_MP4V2
#include "Mp4Maker.h"
#endif //ENABLE_MP4V2

#ifdef  ENABLE_HLS
#include "HLSMaker.h"
#endif //ENABLE_HLS

using namespace std;
using namespace ZL::Player;

namespace ZL {
namespace MediaFile {


class MediaRecorder {
public:
	typedef std::shared_ptr<MediaRecorder> Ptr;
	MediaRecorder(const string &strApp,const string &strId,const std::shared_ptr<PlayerBase> &pPlayer);
	virtual ~MediaRecorder();

	void inputH264(	void *pData,
					uint32_t ui32Length,
					uint32_t ui32TimeStamp,
					int iType);

	void inputAAC(	void *pData,
					uint32_t ui32Length,
					uint32_t ui32TimeStamp);
private:

#ifdef  ENABLE_HLS
	std::shared_ptr<HLSMaker> m_hlsMaker;
#endif //ENABLE_HLS

#ifdef  ENABLE_MP4V2
	std::shared_ptr<Mp4Maker> m_mp4Maker;
#endif //ENABLE_MP4V2

};

} /* namespace MediaFile */
} /* namespace ZL */

#endif /* SRC_MEDIAFILE_MEDIARECORDER_H_ */