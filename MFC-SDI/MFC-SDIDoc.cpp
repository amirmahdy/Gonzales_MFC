#pragma once
// MFC-SDIDoc.cpp : implementation of the CMFCSDIDoc class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFC-SDI.h"
#endif
//#include "atlimage.h"
//#include "afxwin.h"
#include "MFC-SDIDoc.h"
#include "MFC-SDIView.h"
#include "opencv.hpp"
#include "stdio.h"
#include "savebox.h"
//#include <propkey.h>
#include "Report.h"

using namespace cv;
using namespace std;

#ifdef _DEBUG
#pragma comment(lib, "opencv_core246d.lib")
#pragma comment(lib, "opencv_highgui246d.lib")
#pragma comment(lib, "opencv_imgproc246d.lib")
#else
#pragma comment(lib, "opencv_core246.lib")
#pragma comment(lib, "opencv_highgui246.lib")
#pragma comment(lib, "opencv_imgproc246.lib")
#endif


int Mat2CImage  ( Mat mat , CImage &img) ;
void CImage2Mat (Mat &image1, CImage CI);
LPCTSTR _SAVElpszPathName ; 
void sort (int *in ,int size);
int fact = 1;
int _pic = 0;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMFCSDIDoc



IMPLEMENT_DYNCREATE(CMFCSDIDoc, CDocument)

	BEGIN_MESSAGE_MAP(CMFCSDIDoc, CDocument)
		ON_COMMAND(ID_FILTER_BLUR, &CMFCSDIDoc::OnFilterBlur)
		ON_COMMAND(ID_FILTER_SHARP, &CMFCSDIDoc::OnFilterSharp)
		ON_COMMAND(ID_2x, &CMFCSDIDoc::zweix)
		ON_COMMAND(ID_4x, &CMFCSDIDoc::vierx)
		ON_COMMAND(ID_ein, &CMFCSDIDoc::ein)
		ON_COMMAND(ID_minus, &CMFCSDIDoc::minus)
		ON_COMMAND(ID_GENERAL_UNDO, &CMFCSDIDoc::OnGeneralUndo)
		ON_COMMAND(ID_FILTER_GRAYSCALE, &CMFCSDIDoc::OnShrink)
		ON_COMMAND(ID_FILE_SAVE, &CMFCSDIDoc::OnFileSave)
		ON_COMMAND(ID_GENERALUSAGE_ROTATE, &CMFCSDIDoc::ONBITPLANE)
		ON_COMMAND(ID_FILTER_ZOOM, &CMFCSDIDoc::OnFilterZoom)
		ON_COMMAND(ID_DETECTION_COMPONENT, &CMFCSDIDoc::OnDetectionComponent)
		ON_COMMAND(ID_FRQUENCY_MAG, &CMFCSDIDoc::OnFrquencyMag)
		ON_COMMAND(ID_FRQUENCY_LOWPASSFILTER, &CMFCSDIDoc::OnFrquencyLowpassfilter)
		ON_COMMAND(ID_FRQUENCY_HIGHPASSFILTER, &CMFCSDIDoc::OnFrquencyHighpassfilter)
		ON_COMMAND(ID_HIST_HIST, &CMFCSDIDoc::OnHistHist)
		ON_COMMAND(ID_HIST_HIST32784, &CMFCSDIDoc::OnHistHist32784)
		ON_COMMAND(ID_HIST_HIST32785, &CMFCSDIDoc::OnHistHist32785)
		ON_COMMAND(ID_HIST_HIST32786, &CMFCSDIDoc::OnHistHist32786)
		ON_COMMAND(ID_HIST_LOCAL, &CMFCSDIDoc::OnHistLocal)
		ON_COMMAND(ID_ENHANCEMENT_MEDIAN, &CMFCSDIDoc::OnEnhancementMedian)
		ON_COMMAND(ID_ENHANCEMENT_GAUSSIAN, &CMFCSDIDoc::OnEnhancementGaussian)
		ON_COMMAND(ID_DETECTION_LAPLACIAN, &CMFCSDIDoc::OnDetectionLaplacian)
		ON_COMMAND(ID_DETECTION_GRADIENT, &CMFCSDIDoc::OnDetectionGradient)
		ON_COMMAND(ID_FUZZY_EDGE, &CMFCSDIDoc::OnFuzzyEdge)
		ON_COMMAND(ID_FUZZY_INTENSITY, &CMFCSDIDoc::OnFuzzyIntensity)
		ON_COMMAND(ID_ENHANCEMENT_GAMMA, &CMFCSDIDoc::OnEnhancementGamma)
		ON_COMMAND(ID_ENHANCEMENT_LINEAR, &CMFCSDIDoc::OnEnhancementLinear)
		ON_COMMAND(ID_ALIASING_CHESSBOARD, &CMFCSDIDoc::OnAliasingChessboard)
		ON_COMMAND(ID_FRQUENCY_LOWPASSFILTER32814, &CMFCSDIDoc::OnFrquencyLowpassfilter32814)
		ON_COMMAND(ID_FRQUENCY_LOWPASSFILTER32815, &CMFCSDIDoc::OnFrquencyLowpassfilter32815)
		ON_COMMAND(ID_FRQUENCY_HOMOMORPHIC, &CMFCSDIDoc::OnFrquencyHomomorphic)
		ON_COMMAND(ID_FRQUENCY_LAPLACIAN, &CMFCSDIDoc::OnFrquencyLaplacian)
		ON_COMMAND(ID_FRQUENCY_ROTATE, &CMFCSDIDoc::OnFrquencyRotate)
		ON_COMMAND(ID_FRQUENCY_CORELATION, &CMFCSDIDoc::OnFrquencyCorelation)
		ON_COMMAND(ID_PROJECT_FOCUSING, &CMFCSDIDoc::OnProjectFocusing)
		ON_COMMAND(ID_ENHANCEMENT_GEOMETRIC, &CMFCSDIDoc::OnEnhancementGeometric)
		ON_COMMAND(ID_ENHANCEMENT_ARITHMEAN, &CMFCSDIDoc::OnEnhancementArithmean)
		ON_COMMAND(ID_ENHANCEMENT_ADAPTIVEMEDIAN, &CMFCSDIDoc::OnEnhancementAdaptivemedian)
		ON_COMMAND(ID_ENHANCEMENT_CONTRAHARMONIC, &CMFCSDIDoc::OnEnhancementContraharmonic)
		ON_COMMAND(ID_ENHANCEMENT_MIDPOI, &CMFCSDIDoc::OnEnhancementMidpoi)
		ON_COMMAND(ID_ENHANCEMENT_ALPHA, &CMFCSDIDoc::OnEnhancementAlpha)
		ON_COMMAND(ID_ENHANCEMENT_PERIODICNOISE, &CMFCSDIDoc::OnEnhancementPeriodicnoise)
		ON_COMMAND(ID_FRQUENCY_MAGVIEW, &CMFCSDIDoc::OnFrquencyMagview)
		ON_COMMAND(ID_ENHANCEMENT_RINGFILTER, &CMFCSDIDoc::OnEnhancementRingfilter)
		ON_COMMAND(ID_ENHANCEMENT_NOTCHFILTER, &CMFCSDIDoc::OnEnhancementNotchfilter)
		ON_COMMAND(ID_ENHANCEMENT_ATOMSPHERICTURB, &CMFCSDIDoc::OnEnhancementAtomsphericturb)
		ON_COMMAND(ID_ENHANCEMENT_MOTIONBLUR, &CMFCSDIDoc::OnEnhancementMotionblur)
		ON_COMMAND(ID_COLORFULL_FALSECOLOR, &CMFCSDIDoc::OnColorfullFalsecolor)
		ON_COMMAND(ID_COLORFULL_BOOSTINGCONT, &CMFCSDIDoc::OnColorfullBoostingcont)
		ON_COMMAND(ID_COLORFULL_NEGATIVE, &CMFCSDIDoc::OnColorfullNegative)
		ON_COMMAND(ID_COLORFULL_EXTRACTION, &CMFCSDIDoc::OnColorfullExtraction)
		ON_COMMAND(ID_COLORFULL_EQUALIZATION, &CMFCSDIDoc::OnColorfullEqualization)
		ON_COMMAND(ID_COLORFULL_HSI, &CMFCSDIDoc::OnColorfullHsi)
		ON_COMMAND(ID_COLORFULL_EDGEDETECTION, &CMFCSDIDoc::OnColorfullEdgedetection)
		ON_COMMAND(ID_ENHANCEMENT_GEOMETRICTRANS, &CMFCSDIDoc::OnEnhancementGeometrictrans)
		ON_COMMAND(ID_WAVELET_DEBUACHI, &CMFCSDIDoc::OnWaveletDebuachi)
		ON_COMMAND(ID_MORPHOLOG_DILATION, &CMFCSDIDoc::OnMorphologDilation)
		ON_COMMAND(ID_MORPHOLOG_EROTION, &CMFCSDIDoc::OnMorphologErotion)
		ON_COMMAND(ID_MORPHOLOG_OPENING, &CMFCSDIDoc::OnMorphologOpening)
		ON_COMMAND(ID_MORPHOLOG_CLOSING, &CMFCSDIDoc::OnMorphologClosing)
		ON_COMMAND(ID_MORPHOLOG_32850, &CMFCSDIDoc::OnMorpholog32850)
		ON_COMMAND(ID_MORPHOLOG_HITORMISS, &CMFCSDIDoc::OnMorphologHitormiss)
		ON_COMMAND(ID_MORPHOLOG_BOUNDARYEXTRAC, &CMFCSDIDoc::OnMorphologBoundaryextrac)
		ON_COMMAND(ID_MORPHOLOG_REGIONFILLING, &CMFCSDIDoc::OnMorphologRegionfilling)
		ON_COMMAND(ID_SEGMENTATION_LINKING, &CMFCSDIDoc::OnSegmentationLinking)
		ON_COMMAND(ID_SEGMENTATION_LINEDETEC, &CMFCSDIDoc::OnSegmentationLinedetec)
		ON_COMMAND(ID_SEGMENTATION_CIRCLEDETEC, &CMFCSDIDoc::OnSegmentationCircledetec)
		ON_COMMAND(ID_MORPHOLOG_CONVEX, &CMFCSDIDoc::OnMorphologConvex)
		ON_COMMAND(ID_ENHANCEMENT_INVERSEFILT, &CMFCSDIDoc::OnEnhancementInversefilt)
		ON_COMMAND(ID_ENHANCEMENT_MOTIONBLURSPAT, &CMFCSDIDoc::OnEnhancementMotionblurspat)
		ON_COMMAND(ID_MORPHOLOG_TOPHAT, &CMFCSDIDoc::OnMorphologTophat)
		ON_COMMAND(ID_MORPHOLOG_SKELETON, &CMFCSDIDoc::OnMorphologSkeleton)
	END_MESSAGE_MAP()


	// CMFCSDIDoc construction/destruction

	CMFCSDIDoc::CMFCSDIDoc()
	{

	}

	CMFCSDIDoc::~CMFCSDIDoc()
	{
	}

	BOOL CMFCSDIDoc::OnNewDocument()
	{
		if (!CDocument::OnNewDocument())
			return FALSE;
		// TODO: add reinitialization code here
		// (SDI documents will reuse this document)

		return TRUE;
	}


	void CMFCSDIDoc::Serialize(CArchive& ar)
	{
		if (ar.IsStoring())
		{
			// TODO: add storing code here
		}
		else
		{
			// TODO: add loading code here
		}
	}

#ifdef SHARED_HANDLERS

	// Support for thumbnails
	void CMFCSDIDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
	{
		// Modify this code to draw the document's data
		dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

		CString strText = _T("TODO: implement thumbnail drawing here");
		LOGFONT lf;

		CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
		pDefaultGUIFont->GetLogFont(&lf);
		lf.lfHeight = 36;

		CFont fontDraw;
		fontDraw.CreateFontIndirect(&lf);

		CFont* pOldFont = dc.SelectObject(&fontDraw);
		dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
		dc.SelectObject(pOldFont);
	}

	// Support for Search Handlers
	void CMFCSDIDoc::InitializeSearchContent()
	{
		CString strSearchContent;
		// Set search contents from document's data. 
		// The content parts should be separated by ";"

		// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
		SetSearchContent(strSearchContent);
	}

	void CMFCSDIDoc::SetSearchContent(const CString& value)
	{
		if (value.IsEmpty())
		{
			RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
		}
		else
		{
			CMFCFilterChunkValueImpl *pChunk = NULL;
			ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
			if (pChunk != NULL)
			{
				pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
				SetChunkValue(pChunk);
			}
		}
	}

#endif 

#ifdef _DEBUG
	void CMFCSDIDoc::AssertValid() const
	{
		CDocument::AssertValid();
	}

	void CMFCSDIDoc::Dump(CDumpContext& dc) const
	{
		CDocument::Dump(dc);
	}
#endif

	BOOL CMFCSDIDoc::OnOpenDocument(LPCTSTR lpszPathName)
	{
		if (!CDocument::OnOpenDocument(lpszPathName))
			return FALSE;
		if(!img.IsNull())
			img.Detach();
		img.Load(lpszPathName);

		return TRUE;
	}

	void CMFCSDIDoc::OnFilterBlur()
	{
		Mat _temp,_tempres;
		CImage2Mat(_temp,img);
		Mat2CImage(_temp,imgprv[_pic]);
		int nc = _temp.channels();
		int kernel_size = 3 ;
		int border = kernel_size/2;
		Mat kernel = Mat::ones( kernel_size, kernel_size, CV_32F )/ (float)(kernel_size*kernel_size);
		_tempres.create(_temp.rows,_temp.cols,_temp.type());
		for(int i =0 ; i<fact; i++)
			filter2D(_temp,_tempres,_tempres.depth(),kernel);
		Mat2CImage(_tempres,img);
		UpdateAllViews(0); _pic ++;
	}

	void CMFCSDIDoc::OnFilterSharp()
	{
		Mat image (img.GetHeight() , img.GetWidth() , CV_8UC3); 
		CImage2Mat (image,img);
		Mat2CImage(image,imgprv[_pic]);
		Mat image1 (img.GetHeight() , img.GetWidth() , CV_8UC3);;
		Mat kern = (Mat_<char>(3,3) << 0, -1, 0,
			-1, 5, -1,
			0, -1, 0);
		for(int i =0 ; i<fact; i++)
			filter2D(image, image1, image.depth(), kern );
		Mat2CImage (image1, img);
		UpdateAllViews(0); _pic ++;
	}

	void CMFCSDIDoc::OnShrink()
	{
		Mat mat (img.GetHeight() , img.GetWidth() , CV_8UC3); 
		Mat matres ;
		int m_sliderval = 2;
		for(int rpt = 0 ; rpt < fact ; rpt++ )
		{
			CImage2Mat(mat,img);
			Mat2CImage(mat,imgprv[_pic]);
			int nl = mat.rows;
			int nc = (mat.cols)*(mat.channels()) ; 
			matres.create(nl/m_sliderval,mat.cols/m_sliderval,mat.type());
			int jj =0 ;
			for(int j=0 ; j< ((nl / m_sliderval)); j++)
			{
				uchar* data = matres.ptr<uchar>(j);
				uchar* _data = mat.ptr<uchar>(jj);
				for(int i =0 ; i<(nc/m_sliderval) ;i++)
				{
					data[i] = _data[i*m_sliderval] ;
				}
				jj = jj + m_sliderval;
			}
			Mat2CImage(matres,img);
		}
		UpdateAllViews(0); _pic ++;
	}

	void CMFCSDIDoc::OnGeneralUndo()
	{
		_pic -- ;
		if(_pic<0) _pic = 0;
		if(imgprv[0].IsNull()==0)
		{
			img.Detach();
			Mat xcx;
			CImage2Mat(xcx,imgprv[_pic]);
			Mat2CImage(xcx,img);
		}UpdateAllViews(0);

	}

	BOOL CMFCSDIDoc::OnSaveDocument(LPCTSTR lpszPathName)
	{
		if (!CDocument::OnSaveDocument(lpszPathName))
			return FALSE;
		img.Save(lpszPathName);
		return TRUE;
	}

	void CMFCSDIDoc::OnFileSave()
	{
		savebox Dlg;
		Dlg.DoModal();
		if(Dlg._Sflag)
			img.Save(  Dlg.m_savebrowseval ); 
	}

	void CMFCSDIDoc::ONBITPLANE()
	{

		Mat _temp ;
		CImage2Mat(_temp,img);
		Mat2CImage(_temp,imgprv[_pic]);
		int nl = _temp.rows;
		int nc = (_temp.cols)*(_temp.channels()) ;

		Mat _tempres(nl,_temp.cols,_temp.type()); Mat _temp0(nl,_temp.cols,_temp.type()) ; Mat _temp1(nl,_temp.cols,_temp.type());
		Mat _temp2(nl,_temp.cols,_temp.type()) ; Mat _temp3(nl,_temp.cols,_temp.type()) ;Mat _temp4(nl,_temp.cols,_temp.type());
		Mat _temp5(nl,_temp.cols,_temp.type()); Mat _temp6(nl,_temp.cols,_temp.type());Mat  _temp7(nl,_temp.cols,_temp.type());

		for(int j = 0 ; j < (nl); j ++)
		{
			uchar* _datares = _tempres.ptr<uchar>(j);
			uchar* _data  = _temp.ptr<uchar>(j);
			uchar* _data0 = _temp0.ptr<uchar>(j);
			uchar* _data1 = _temp1.ptr<uchar>(j);
			uchar* _data2 = _temp2.ptr<uchar>(j);
			uchar* _data3 = _temp3.ptr<uchar>(j);
			uchar* _data4 = _temp4.ptr<uchar>(j);
			uchar* _data5 = _temp5.ptr<uchar>(j);
			uchar* _data6 = _temp6.ptr<uchar>(j);
			uchar* _data7 = _temp7.ptr<uchar>(j);
			for ( int i=0 ; i < nc ;i++)
			{
				if(_data[i] >= 128 ) {_data7[i] = 255; _data[i] -= 128 ;}
				else {_data7[i] = 0;}

				if(_data[i] >= 64 ) {_data6[i] = 255; _data[i] -= 64 ;}
				else {_data6[i] = 0;}

				if(_data[i] >= 32 ) {_data5[i] = 255; _data[i] -= 32 ;}
				else {_data5[i] = 0;}

				if(_data[i] >= 16 ) {_data4[i] = 255; _data[i] -= 16 ;}
				else {_data4[i] = 0;}

				if(_data[i] >= 8 ) {_data3[i] = 255; _data[i] -= 8 ;}
				else {_data3[i] = 0;}

				if(_data[i] >= 4 ) {_data2[i] = 255; _data[i] -= 4 ;}
				else {_data2[i] = 0;}

				if(_data[i] >= 2 ) {_data1[i] = 255; _data[i] -= 2 ;}
				else {_data1[i] = 0;}

				if(_data[i] >= 1 ) {_data0[i] = 255; _data[i] -= 1 ;}
				else {_data0[i] = 0;}

				_datares[i] = ((_data7[i] + _data6[i] + _data5[i] + _data4[i] + _data3[i])/5);

			}
		}
		Mat2CImage(_tempres,img);
		UpdateAllViews(0); _pic ++;


	}

	void sort (int *in ,int size)
	{

		for(int i =0 ; i < size ; i++)
			for ( int j =0 ; j < size ; j++)
			{
				int temp =0 ;
				if(in[j] < in [i])
				{
					temp = in[j];
					in[j] = in[i] ;
					in[i] = temp;
				}
			}
	}

	int Mat2CImage ( Mat mat , CImage &img) 

	{
		if( mat.empty())
			return (-1);
		int nBPP = mat.channels()*8;
		if(img.IsNull()==0)
			img.Detach();
		img.Create(mat.cols, mat.rows, nBPP);
		if(nBPP == 8)
		{
			static RGBQUAD pRGB[256];
			for (int i = 0; i < 256; i++)
				pRGB[i].rgbBlue = pRGB[i].rgbGreen = pRGB[i].rgbRed = i;
			img.SetColorTable(0, 256, pRGB);
		}
		uchar* psrc = mat.data;
		uchar* pdst = (uchar*) img.GetBits();
		int imgPitch = img.GetPitch();
		for(int y = 0; y < mat.rows; y++)
		{
			memcpy(pdst, psrc, mat.cols*mat.channels());//mat->step is incorrect for those images created by roi (sub-images!)
			psrc += mat.step;
			pdst += imgPitch;
		}

	}

	void CImage2Mat (Mat &image1 , CImage CI)
	{
		if((CI.GetBPP() / 8) == 3)
			image1.create(CI.GetHeight() , CI.GetWidth() , CV_8UC3);
		else 
			image1.create(CI.GetHeight() , CI.GetWidth() , CV_8UC1);
		int pitch = CI.GetPitch();
		int step = image1.step;
		uchar* p2 = image1.data;
		uchar* p1 = (uchar*)CI.GetBits();
		for (int i = 0; i < CI.GetHeight(); i++)
		{
			memcpy(p2, p1, step);
			p1 += pitch;
			p2 += step;
		}

	}

	void CMFCSDIDoc::OnFilterZoom()
	{

		Mat _temp , _tempres;
		CImage2Mat(_temp,img);
		Mat2CImage(_temp,imgprv[_pic]);
		int nl = _temp.rows;
		int nc = (_temp.cols)*(_temp.channels()) ; 
		_tempres.create(2*nl,_temp.cols*2,_temp.type());
		for(int j=0 ; j< (2*(nl) - 2); j++)
		{
			uchar* data = _tempres.ptr<uchar>(j);
			uchar* _data = _temp.ptr<uchar>((j/2));

			for(int i = 0 ; i < 2*nc  ; i++)
			{
				int a=0 , b=0 , c=0 , d=0 , Point =0;
				if((i%3 == 0) && ( (i/3)%2 == 0) && ( j%2 == 0)) data[i] = _data[i/2] ;
				else if(((i-(i%3) )% 2== 0) && ( (i-(i%3) )%2 == 0) && (j%2 == 0)) data[i] = _data[((i/2)+(i%2))] ;
				else
				{

					Point = i - (((i/3) + 1)/2)*3 ;
					data[i] = ( _data[Point] + _data[(Point+3)] + _data[(Point+nc)] + _data[(Point+3+nc)] )/4;

				}


			}
		}
		Mat2CImage(_tempres,img);
		UpdateAllViews(0); _pic ++;
	}

	void CMFCSDIDoc::OnDetectionComponent()
	{
		Mat _temp  ;
		CImage2Mat(_temp,img);
		Mat2CImage(_temp,imgprv[_pic]);
		int nl = _temp.rows;
		int nc = (_temp.cols)*(_temp.channels()) ; 
		int cnt =0 ;

		cnt = 0;
		for(int j = 2 ; j < (nl - 2 ); j ++)
		{
			uchar* _data = _temp.ptr<uchar>(j);
			for ( int i=3 ; i < (nc - 3) ;)
			{
				if((_data[i] == 0) && (_data[i+3] == 0) && (_data[i-3] == 0) && (_data[i+nc] == 0)	&& (_data[i-nc] == 0) && (_data[i+3+nc]  == 0) && (_data[i-3+nc] == 0) && (_data[i+3-nc] == 0) && (_data[i-3-nc] == 0))
				{
					if( cnt == 0)
					{
						cnt ++ ;
						_data[i] = 250 - 40 ;
						_data[i-3] = 250 - 40 ;
						_data[i+3] = 250 - 40 ;
						_data[i+nc] = 250 - 40 ;
						_data[i-nc] = 250 - 40 ;
						_data[i-nc+3] = 250 - 40 ;
						_data[i-nc-3] = 250 - 40 ;
						_data[i+nc+3] = 250 - 40 ;
						_data[i+nc-3] = 250 - 40 ;

					}
				}
				i = i+_temp.channels();
			}
		}
		for( int esd =0 ; esd <70 ; esd++)
		{
			for(int j = 2 ; j < (nl - 2 ); j++)
			{
				uchar* _data = _temp.ptr<uchar>(j);
				for ( int i=3 ; i < (nc - 3) ;)
				{
					if(_data[i] == 250 - 40)
					{
						if(_data[i+3] == 0 )
							_data[i+3] = 250 - 40;
						if(_data[i-3] == 0 )
							_data[i-3] = 250 - 40;
						if(_data[i+nc] == 0 )
							_data[i+nc] = 250 - 40;
						if(_data[i-nc] == 0 )
							_data[i-nc] = 250 - 40;
						if(_data[i+3+nc] == 0 )
							_data[i+3+nc] = 250 - 40;
						if(_data[i-3+nc] == 0 )
							_data[i-3+nc] = 250 - 40;
						if(_data[i-nc+3] == 0 )
							_data[i-nc+3] = 250 - 40;
						if(_data[i-nc-3] == 0 )
							_data[i-nc-3] = 250 - 40;
					}
					i = i+_temp.channels();
				}
			}
		}
		Mat2CImage(_temp,img);
		UpdateAllViews(0); _pic ++;
	}

	void CMFCSDIDoc::OnFrquencyMag()
	{
		Mat I,J;
		CImage2Mat(I,img);
		Mat2CImage(I,imgprv[_pic]);
		CImage tempJ;
		savebox Dlg;
t1:
		Dlg.DoModal();
		if(Dlg._Sflag)
			tempJ.Load(Dlg.m_savebrowseval);
		if(tempJ.IsNull())
		{	
			goto t1;
		}
		CImage2Mat(J,tempJ);
		J.convertTo(J, CV_32F);
		I.convertTo(I, CV_32F);

		Mat paddedI;                           
		int m = getOptimalDFTSize( I.rows );
		int n = getOptimalDFTSize( I.cols ); // on the border add zero values
		copyMakeBorder(I, paddedI, 0, m - I.rows, 0, n - I.cols, BORDER_CONSTANT, Scalar::all(0));
		Mat planesI[] = {Mat_<float>(paddedI), Mat::zeros(paddedI.size(), CV_32F)}; 
		Mat complexI;
		merge(planesI, 2, complexI);         // Add to the expanded another plane with zeros
		dft(complexI, complexI , cv::DFT_SCALE|cv::DFT_COMPLEX_OUTPUT);            // this way the result may fit in the source matrix
		split(complexI, planesI);                   // planes[0] = Re(DFT(I), planes[1] = Im(DFT(I))
		Mat magI ,phasI;
		magnitude(planesI[0],planesI[1],magI);
		phase(planesI[0],planesI[1],phasI);

		Mat paddedJ;                            //expand input image to optimal size
		m = getOptimalDFTSize( J.rows );
		n = getOptimalDFTSize( J.cols ); // on the border add zero values
		copyMakeBorder(J, paddedJ, 0, m - J.rows, 0, n - J.cols, BORDER_CONSTANT, Scalar::all(0));
		Mat planesJ[] = {Mat_<float>(paddedJ), Mat::zeros(paddedJ.size(), CV_32F)}; 
		Mat complexJ;
		merge(planesJ, 2, complexJ);         // Add to the expanded another plane with zeros
		dft(complexJ, complexJ, cv::DFT_SCALE|cv::DFT_COMPLEX_OUTPUT);               // this way the result may fit in the source matrix
		split(complexJ, planesJ);                   // planes[0] = Re(DFT(I), planes[1] = Im(DFT(I))
		Mat magJ ,phasJ;
		magnitude(planesJ[0],planesJ[1],magJ);
		phase(planesJ[0],planesJ[1],phasJ);


		/*
		log(magJ,magJ);
		int cx = magJ.cols/2;
		int cy = magJ.rows/2;
		Mat q0(magJ, Rect(0, 0, cx, cy));
		Mat q1(magJ, Rect(cx, 0, cx, cy));
		Mat q2(magJ, Rect(0, cy, cx, cy));
		Mat q3(magJ, Rect(cx, cy, cx, cy));
		Mat tmp;
		q0.copyTo(tmp);
		q3.copyTo(q0);
		tmp.copyTo(q3);

		q1.copyTo(tmp);
		q2.copyTo(q1);
		tmp.copyTo(q2);

		normalize(magJ, magJ, 0, 1, CV_MINMAX);
		magJ = magJ * 256 ;
		imwrite("test.jpg",magJ);
		*/

		Mat planesO[2];
		Mat complexO;
		polarToCart(magJ,phasI,planesO[0],planesO[1]);
		merge(planesO,2,complexO);
		dft(complexO,complexO,cv::DFT_INVERSE);
		split(complexO,planesO);
		planesO[0].convertTo(planesO[0],CV_8UC1);
		Mat2CImage(planesO[0],img);
		UpdateAllViews(0); _pic ++;


	}

	void CMFCSDIDoc::OnFrquencyLowpassfilter()
	{
		Mat J;
		CImage2Mat(J,img);
		Mat2CImage(J,imgprv[_pic]);
		if(J.step[1] == 3)
			cvtColor( J, J, CV_BGR2GRAY );
		J.convertTo(J, CV_32F);
		Mat paddedJ;                            //expand input image to optimal size
		int m = getOptimalDFTSize( J.rows );
		int n = getOptimalDFTSize( J.cols ); // on the border add zero values
		copyMakeBorder(J, paddedJ, 0, m - J.rows, 0, n - J.cols, BORDER_CONSTANT, Scalar::all(0));
		Mat planesJ[] = {Mat_<float>(paddedJ), Mat::zeros(paddedJ.size(), CV_32F)}; 
		Mat complexJ;
		merge(planesJ, 2, complexJ);         // Add to the expanded another plane with zeros
		dft(complexJ, complexJ , cv::DFT_SCALE|cv::DFT_COMPLEX_OUTPUT);            // this way the result may fit in the source matrix
		split(complexJ, planesJ);                   // planes[0] = Re(DFT(I), planes[1] = Im(DFT(I))
		Mat magJ ,phasJ;
		magnitude(planesJ[0],planesJ[1],magJ);
		phase(planesJ[0],planesJ[1],phasJ);
		int cx = magJ.cols/2;
		int cy = magJ.rows/2;
		Mat q0(magJ, Rect(0, 0, cx, cy));
		Mat q1(magJ, Rect(cx, 0, cx, cy));
		Mat q2(magJ, Rect(0, cy, cx, cy));
		Mat q3(magJ, Rect(cx, cy, cx, cy));
		Mat tmp;
		q0.copyTo(tmp);
		q3.copyTo(q0);
		tmp.copyTo(q3);
		q1.copyTo(tmp);
		q2.copyTo(q1);
		tmp.copyTo(q2);

		//************ END OF FRQ ACQUISITION AND SHIFT *************
		//******** BEGINING OF FILTER DEFINITION *********************************
		Mat H;
		H = Mat::ones(magJ.rows,magJ.cols,magJ.type());
		int dims = 100;
		int nc = magJ.step[1];
		int limity = (cy+dims);
		int limitx = nc*(cx+dims);
		int starty = (cy-dims);
		int startx = nc*(cx-dims);
		for(int j=starty;j<limity;j++)
		{uchar *filter = H.ptr<uchar>(j);
		for(int i=startx;i<limitx;i++)
		{
			if(sqrt(pow(float(i-nc*cx),2) + pow(float(j-cy),2) ) <= dims)
				filter[i] = 0;
		}
		}
		H = H*(-1);
		H = H + 1;
		//******** END OF FILTER *********************************
		multiply(magJ,H,magJ);
		Mat q5(magJ, Rect(0, 0, cx, cy));
		Mat q6(magJ, Rect(cx, 0, cx, cy));
		Mat q7(magJ, Rect(0, cy, cx, cy));
		Mat q8(magJ, Rect(cx, cy, cx, cy));
		tmp;
		q0.copyTo(tmp);
		q3.copyTo(q0);
		tmp.copyTo(q3);
		q1.copyTo(tmp);
		q2.copyTo(q1);
		tmp.copyTo(q2);
		//***************** END OF MAG OPERATIONS **************

		/*log(magJ,magJ);
		normalize(magJ, magJ, 0, 1, CV_MINMAX);
		magJ = magJ*256;
		imwrite("filt.jpg",magJ);
		*/
		Mat planesO[2];
		Mat complexO;
		polarToCart(magJ,phasJ,planesO[0],planesO[1]);
		merge(planesO,2,complexO);
		dft(complexO,complexO,cv::DFT_INVERSE);
		split(complexO,planesO);
		planesO[0].convertTo(planesO[0],CV_8UC1);
		Mat2CImage(planesO[0],img);
		UpdateAllViews(0); _pic ++;
	}	

	void CMFCSDIDoc::OnFrquencyHighpassfilter()
	{
		Mat J;
		CImage2Mat(J,img);
		Mat2CImage(J,imgprv[_pic]);
		if(J.step[1] == 3)
			cvtColor( J, J, CV_BGR2GRAY );
		J.convertTo(J, CV_32F);
		Mat paddedJ;                            //expand input image to optimal size
		int m = getOptimalDFTSize( J.rows );
		int n = getOptimalDFTSize( J.cols ); // on the border add zero values
		copyMakeBorder(J, paddedJ, 0, m - J.rows, 0, n - J.cols, BORDER_CONSTANT, Scalar::all(0));
		Mat planesJ[] = {Mat_<float>(paddedJ), Mat::zeros(paddedJ.size(), CV_32F)}; 
		Mat complexJ;
		merge(planesJ, 2, complexJ);         // Add to the expanded another plane with zeros
		dft(complexJ, complexJ , cv::DFT_SCALE|cv::DFT_COMPLEX_OUTPUT);            // this way the result may fit in the source matrix
		split(complexJ, planesJ);                   // planes[0] = Re(DFT(I), planes[1] = Im(DFT(I))
		Mat magJ ,phasJ;
		magnitude(planesJ[0],planesJ[1],magJ);
		phase(planesJ[0],planesJ[1],phasJ);
		int cx = magJ.cols/2;
		int cy = magJ.rows/2;
		Mat q0(magJ, Rect(0, 0, cx, cy));
		Mat q1(magJ, Rect(cx, 0, cx, cy));
		Mat q2(magJ, Rect(0, cy, cx, cy));
		Mat q3(magJ, Rect(cx, cy, cx, cy));
		Mat tmp;
		q0.copyTo(tmp);
		q3.copyTo(q0);
		tmp.copyTo(q3);
		q1.copyTo(tmp);
		q2.copyTo(q1);
		tmp.copyTo(q2);

		//************ END OF FRQ ACQUISITION AND SHIFT *************
		//******** BEGINING OF FILTER DEFINITION *********************************
		Mat H;
		H = Mat::zeros(magJ.rows,magJ.cols,CV_8UC1);
		int dims = 80;
		int nc = magJ.step[1];
		int limity = (cy+dims);
		int limitx = (cx+dims);
		int starty = (cy-dims);
		int startx = (cx-dims);
		for(int j=starty;j<limity;j++)
		{uchar *filter = H.ptr<uchar>(j);
		for(int i=startx;i<limitx;i++)
		{

			if(sqrt(pow(float(i-cx),2) + pow(float(j-cy),2) ) <= dims)
				filter[i] = 1;
		}
		}
		H = 1-H;
		H.convertTo(H,magJ.type());
		//******** END OF FILTER *********************************
		multiply(magJ,H,magJ);
		Mat q5(magJ, Rect(0, 0, cx, cy));
		Mat q6(magJ, Rect(cx, 0, cx, cy));
		Mat q7(magJ, Rect(0, cy, cx, cy));
		Mat q8(magJ, Rect(cx, cy, cx, cy));
		tmp;
		q0.copyTo(tmp);
		q3.copyTo(q0);
		tmp.copyTo(q3);
		q1.copyTo(tmp);
		q2.copyTo(q1);
		tmp.copyTo(q2);
		//***************** END OF MAG OPERATIONS **************
		Mat planesO[2];
		Mat complexO;
		polarToCart(magJ,phasJ,planesO[0],planesO[1]);
		merge(planesO,2,complexO);
		dft(complexO,complexO,cv::DFT_INVERSE);
		split(complexO,planesO);
		planesO[0].convertTo(planesO[0],CV_8UC1);

		Mat2CImage(planesO[0],img);
		UpdateAllViews(0); _pic ++;

	}

	void CMFCSDIDoc::OnHistHist()
	{
		Mat src;
		CImage2Mat (src,img);
		Mat2CImage(src,imgprv[_pic]);
		vector<Mat> bgr_planes;
		split( src, bgr_planes );
		int histSize = 256;
		float range[] = { 0, 256 } ;
		const float* histRange = { range };
		bool uniform = true; bool accumulate = false;
		Mat b_hist, g_hist, r_hist;
		if(src.channels() == 3)
		{calcHist( &bgr_planes[0], 1, 0, Mat(), b_hist, 1, &histSize, &histRange, uniform, accumulate );
		calcHist( &bgr_planes[1], 1, 0, Mat(), g_hist, 1, &histSize, &histRange, uniform, accumulate );
		calcHist( &bgr_planes[2], 1, 0, Mat(), r_hist, 1, &histSize, &histRange, uniform, accumulate );
		}
		else
			calcHist( &bgr_planes[0], 1, 0, Mat(), b_hist, 1, &histSize, &histRange, uniform, accumulate );

		int hist_w = 512; int hist_h = 400;
		int bin_w = cvRound( (double) hist_w/histSize );
		Mat histImage( hist_h, hist_w, CV_8UC3, Scalar( 0,0,0) );
		normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );
		normalize(g_hist, g_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );
		normalize(r_hist, r_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );
		if(src.channels() == 3)
		{for( int i = 1; i < histSize; i++ )
		{
			line( histImage, Point( bin_w*(i-1), hist_h - cvRound(b_hist.at<float>(i-1)) ) ,
				Point( bin_w*(i), hist_h - cvRound(b_hist.at<float>(i)) ),
				Scalar( 255, 0, 0), 2, 8, 0  );
			line( histImage, Point( bin_w*(i-1), hist_h - cvRound(g_hist.at<float>(i-1)) ) ,
				Point( bin_w*(i), hist_h - cvRound(g_hist.at<float>(i)) ),
				Scalar( 0, 255, 0), 2, 8, 0  );
			line( histImage, Point( bin_w*(i-1), hist_h - cvRound(r_hist.at<float>(i-1)) ) ,
				Point( bin_w*(i), hist_h - cvRound(r_hist.at<float>(i)) ),
				Scalar( 0, 0, 255), 2, 8, 0  );
		}}
		else 
			for( int i = 1; i < histSize; i++ )
			{
				line( histImage, Point( bin_w*(i-1), hist_h - cvRound(b_hist.at<float>(i-1)) ) ,
					Point( bin_w*(i), hist_h - cvRound(b_hist.at<float>(i)) ),
					Scalar( 0, 0, 255), 2, 8, 0  );
			}
			Mat2CImage(histImage , img ) ;
			UpdateAllViews(0); _pic ++;
	}

	void CMFCSDIDoc::OnHistHist32784()
	{
		Mat _temp  ;
		CImage2Mat(_temp,img);
		Mat2CImage(_temp,imgprv[_pic]);
		int nl = _temp.rows;
		int nc = (_temp.cols)*(_temp.channels()) ;
		int frq[256] = {};
		int cufrq[256] = {};
		int _frq[256] = {} ;
		int cufrqx[256] = {};
		int ximg[256] = {};
		// ************ frequency of input **********************
		for(int j = 0 ; j < (nl); j ++)
		{
			uchar* _data = _temp.ptr<uchar>(j);
			for ( int i=0 ; i < nc ;)
			{
				frq[(_data[i])] ++ ;
				i = i + _temp.channels() ;
			}
		}
		// ************ cumulative frequency of input ***********

		for(int i =0 ; i< 256 ; i++)
		{
			cufrq[i] = frq[i] + cufrq[max((i-1),0)] ;
		}
		// ************ hist equl. according to cufeq. ***********
		int fact = (cufrq[255] / 256) ;
		for(int i =0 ; i< 256 ; i++)		_frq[i] = fact ;

		for(int i =0 ; i< 256 ; i++)		cufrqx[i] = _frq[i] + cufrqx[max((i-1),0)] ;
		//**************** compare between input cufrq and cufrqx ****
		for( int i =0 ; i<256 ; i++)
			for( int j =0 ; j<256 ; j++)
			{
				if(cufrq[i] == cufrqx[j]) {ximg[i] = j;}
				else { 
					for( int k = 0 ; k<1000 ; k++)
						if((cufrq[i] == (cufrqx[j] - k )) || (cufrq[i] == (cufrqx[j] + k )))
						{ximg[i] = j;
					break;
					}
				}
			}
			for(int j = 0 ; j < (nl); j ++)
			{
				uchar* _data = _temp.ptr<uchar>(j);
				for ( int i=0 ; i < nc ;i++)
				{
					_data[i] = ximg[_data[i]] ;
				}
			}


			Mat2CImage(_temp,img);
			UpdateAllViews(0); _pic ++;
	}

	void CMFCSDIDoc::OnHistHist32785()
	{
		Mat _temp  ;
		CImage2Mat(_temp,img);
		Mat2CImage(_temp,imgprv[_pic]);
		int nl = _temp.rows;
		int nc = (_temp.cols)*(_temp.channels()) ;
		int frq[256] = {};
		int s[256] = {};
		int _cufrq[256] = {};
		int* Z = new int [256]()  ;
		int _OUT[256] = {} ;

		float raw_desired[256] = {0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,3 ,3 ,8 ,6 ,22 ,23 ,36 ,59 ,80 ,90 ,120 ,277 ,563 ,1519 ,6508 ,84088 ,5834 ,2574 ,1842 ,1485 ,1271 ,1220 ,1172 ,1056 ,1042 ,1076 ,984 ,938 ,902 ,959 ,928 ,878 ,918 ,810 ,804 ,751 ,670 ,672 ,696 ,588 ,623 ,567 ,559 ,530 ,524 ,503 ,456 ,474 ,468 ,441 ,531 ,497 ,501 ,475 ,505 ,486 ,431 ,497 ,439 ,461 ,477 ,467 ,507 ,468 ,495 ,462 ,479 ,450 ,461 ,439 ,454 ,468 ,419 ,445 ,441 ,416 ,366 ,387 ,357 ,369 ,319 ,310 ,352 ,321 ,307 ,292 ,338 ,318 ,323 ,326 ,326 ,339 ,275 ,290 ,253 ,270 ,295 ,258 ,255 ,261 ,259 ,287 ,261 ,240 ,246 ,229 ,226 ,194 ,218 ,206 ,210 ,217 ,197 ,186 ,209 ,191 ,173 ,186 ,175 ,158 ,149 ,182 ,146 ,156 ,142 ,145 ,134 ,128 ,111 ,122 ,108 ,116 ,115 ,114 ,97 ,91 ,81 ,100 ,108 ,101 ,97 ,114 ,106 ,124 ,132 ,147 ,165 ,135 ,153 ,175 ,196 ,184 ,186 ,174 ,189 ,217 ,232 ,202 ,248 ,399 ,567 ,592 ,641 ,576 ,501 ,553 ,536 ,546 ,562 ,546 ,540 ,570 ,518 ,491 ,451 ,434 ,437 ,365 ,371 ,333 ,326 ,320 ,321 ,331 ,347 ,355 ,330 ,330 ,335 ,314 ,336 ,333 ,304 ,206 ,213 ,238 ,259 ,239 ,189 ,174 ,160 ,161 ,165 ,148 ,129 ,122 ,142 ,137 ,113 ,114 ,109 ,100 ,99 ,89 ,87 ,89 ,79 ,113 ,163 ,295  } ;
		// ************ frequency of input **********************
		for(int j = 0 ; j < (nl); j ++)
		{
			uchar* _data = _temp.ptr<uchar>(j);
			for ( int i=0 ; i < nc ;)
			{
				frq[(_data[i])] ++ ;
				i = i + _temp.channels() ;
			}
		}
		// ************ hist equl. according to cufeq. ***********
		for(int i =0 ; i< 256 ; i++)
		{
			s[i] = frq[i] + s[max((i-1),0)] ;
		}

		for(int i =0 ; i< 256 ; i++)
		{
			_cufrq[i] = raw_desired[i] + _cufrq[max((i-1),0)] ;
		}

		int fact = ( _cufrq[255] / 256 );

		for(int i =0 ; i< 256 ; i++)
		{
			Z[(_cufrq[i] / fact)] = i;
		}


		fact = ( s[255] / 256 );
		for(int i = 0 ; i < 256 ; i++)
			_OUT[i] = Z[(s[i] / fact)];

		for(int j = 0 ; j < (nl); j ++)
		{
			uchar* _data = _temp.ptr<uchar>(j);
			for ( int i=0 ; i < nc ;i++)
			{
				_data[i] = _OUT[(_data[i])];
			}
		}

		Mat2CImage(_temp,img);
		UpdateAllViews(0); _pic ++;
	}

	void CMFCSDIDoc::OnHistHist32786()
	{
		Mat _temp  ;
		CImage2Mat(_temp,img);
		Mat2CImage(_temp,imgprv[_pic]);
		int step = 16*fact;
		int stp = step*_temp.channels();
		int nl = (_temp.rows -step);
		int nc = (_temp.cols - step);
		for(int dmsy = 0 ; dmsy <nl ;)
		{for(int dmsx = 0 ; dmsx < nc;)
		{
			Mat sub(_temp,Rect(dmsx,dmsy,step,step));
			int frq[256] = {};
			int cufrq[256] = {};
			int _frq[256] = {} ;
			int cufrqx[256] = {};
			int ximg[256] = {};
			// ************ frequency of input **********************
			for(int j = 0 ; j < step; j ++)
			{
				uchar* _data = sub.ptr<uchar>(j);
				for ( int i=0 ; i < stp ;)
				{
					frq[(_data[i])] ++ ;
					i = i + sub.channels() ;
				}
			}
			// ************ cumulative frequency of input ***********

			for(int i =0 ; i< 256 ; i++)
			{
				cufrq[i] = frq[i] + cufrq[max((i-1),0)] ;
			}
			// ************ hist equl. according to cufeq. ***********
			int fact =  int(cufrq[255] / 256) ;
			for(int i =0 ; i< 256 ; i++)		_frq[i] = fact ;

			for(int i =0 ; i< 256 ; i++)		cufrqx[i] = _frq[i] + cufrqx[max((i-1),0)] ;
			//**************** compare between input cufrq and cufrqx ****
			for( int i =0 ; i<256 ; i++)
				for( int j =0 ; j<256 ; j++)
				{
					if(cufrq[i] == cufrqx[j]) {ximg[i] = j;}
					else { 
						for( int k = 0 ; k<10 ; k++)
							if((cufrq[i] == (cufrqx[j] - k )) || (cufrq[i] == (cufrqx[j] + k )))
							{ximg[i] = j;
						break;
						}
					}
				}
				for(int j = 0 ; j < step; j ++)
				{
					uchar* _data = sub.ptr<uchar>(j);
					for ( int i=0 ; i < stp ;i++)
					{
						_data[i] = ximg[_data[i]] ;
					}
				}
				dmsx = dmsx + step;
		}
		dmsy = dmsy + step;
		}
		Mat2CImage(_temp,img);
		UpdateAllViews(0); _pic ++;
	}

	void CMFCSDIDoc::OnHistLocal()
	{
		Mat _temp;
		CImage2Mat(_temp,img);
		Mat2CImage(_temp,imgprv[_pic]);
		int kernel_size = 3*fact;
		int nc = _temp.channels();
		float _mean = 0 , _std = 0	;
		//************************ Mean begins ****************************************
		for(int j =0 ; j< _temp.rows ; j++)
		{	uchar* current = _temp.ptr<uchar>(j);
		for(int i =0 ; i<( _temp.cols*nc ); i++)
			_mean += current[i];
		}
		_mean = _mean / (nc*_temp.rows * _temp.cols );
		//*********************************** STD begins ******************************
		for(int j =0 ; j< _temp.rows ; j++)
		{	uchar* current = _temp.ptr<uchar>(j);
		for(int i =0 ; i<( _temp.cols*nc ); i++)
			_std += pow((double)(current[i] - _mean),2);
		}
		_std = _std / (nc*_temp.rows * _temp.cols );
		_std = sqrt((double)_std);   
		//***************************** Local enhancement begins **********************
		int dims = 3; // 3*3 neighbour hood
		int limity = _temp.rows - dims ;
		int limitx = _temp.cols - nc*dims ;

		const float k0 = float(0.4 * _mean) ,k1 = float(0.02 * _std )  , k2 = float(0.4* _std ) , E = 4; 
		for(int j = 0  ; j < limity ; j++)
			for(int i = 0 ; i< limitx ;)
			{
				Mat sub(_temp,Rect(i,j,dims,dims));
				float _meanprim = 0;
				float _stdprim  = 0;
				for(int l = 0 ; l < dims; l++)
				{
					const uchar* _data = sub.ptr<uchar>(l);
					for ( int k=0 ; k < dims*nc ;k++)
						_meanprim += _data[k];		
				}
				_meanprim = float(float(_meanprim) / float(dims*dims*nc));
				for(int l = 0 ; l < dims; l++)
				{
					uchar* _data = sub.ptr<uchar>(l);
					for ( int k = 0 ; k < dims*nc ;k++)
						_stdprim += pow((double)(_meanprim - _data[k]),2);		
				}
				_stdprim = float(float(_stdprim) / float(dims*dims*nc));
				_stdprim = sqrt((double)_stdprim);   
				uchar* data = sub.ptr<uchar>(1);
				if((k0 >= _meanprim) && (k1 <= _stdprim) && (k2 >= _stdprim))
					for(int dummy = 0 ; dummy <nc ; dummy ++)
						data[nc+dummy] = data[nc+dummy] * E;

				i ++;
			}
			Mat2CImage(_temp,img);
			UpdateAllViews(0); _pic ++;
	}

	void CMFCSDIDoc::OnEnhancementMedian()
	{
		Mat _temp;
		CImage2Mat(_temp,img);
		Mat2CImage(_temp,imgprv[_pic]);
		int nc = _temp.channels();
		int dimens = 2*(fact)+1;
		int limitx = (_temp.cols - dimens) ;
		int limity = (_temp.rows - dimens) ; 

		for(int j =(dimens/2); j< limity ; j++)
		{
			uchar* _datares = _temp.ptr<uchar>(j);
			for(int i =(dimens/2) ; i < limitx ;i++)
			{
				int *vect = new int [nc*dimens*dimens];
				Mat sub(_temp,Rect(i,j,dimens,dimens));
				for(int klm = 0 ; klm < (nc) ; klm ++)
				{	
					for(int k = 0 ; k < dimens ; k ++)
					{
						uchar* _data = sub.ptr<uchar>(k);
						for(int l = 0 ; l < dimens ; l++)
							vect[k*dimens + l] = _data[l] ;
					}

					sort(vect,(dimens*dimens));
					_datares[nc*i+klm] = vect[(int((dimens*dimens)/2))];

				}
				delete(vect);
			}
		}

		Mat2CImage(_temp,img);
		UpdateAllViews(0); _pic ++;
	}

	void CMFCSDIDoc::OnEnhancementGaussian()
	{
		Mat _temp;
		CImage2Mat(_temp,img);
		Mat2CImage(_temp,imgprv[_pic]);
		int nChannels = _temp.channels();
		for(int j = 1 ; j < _temp.rows - 1; ++j)
		{
			uchar* previous = _temp.ptr<uchar>(j - 1);
			uchar* current = _temp.ptr<uchar>(j );
			uchar* next = _temp.ptr<uchar>(j + 1);
			for(int i= nChannels;i < nChannels*(_temp.cols-nChannels); ++i)
			{
				current[i] = ((current[i]+current[i-nChannels] + current[i+nChannels] + previous[i] +previous[i-nChannels] +previous[i+nChannels] 
				+ next[i]+ next[i-nChannels]+ next[i+nChannels])/9);
			}
		}

		_temp.row(0).setTo(Scalar(0)); // The top row
		_temp.row(_temp.rows-1).setTo(Scalar(0)); // The bottom row
		_temp.col(0).setTo(Scalar(0)); // The left column
		_temp.col(_temp.cols-1).setTo(Scalar(0)); // The right column

		Mat2CImage(_temp,img);
		UpdateAllViews(0); _pic ++;
	}

	void CMFCSDIDoc::OnDetectionLaplacian()
	{
		Mat _temp,_tempres;
		CImage2Mat(_temp,img);
		Mat2CImage(_temp,imgprv[_pic]);
		int nc = _temp.channels();
		int kernel_size = 3*fact;
		int border = kernel_size/2;
		Mat kern = (Mat_<char>(3,3) << 0, -1, 0,
			-1, 4, -1,
			0, -1, 0);
		_tempres.create(_temp.rows,_temp.cols,_temp.type());

		filter2D(_temp,_tempres,_temp.depth(),kern);

		Mat2CImage(_tempres,img);
		UpdateAllViews(0); _pic ++;
	}

	void CMFCSDIDoc::OnDetectionGradient()
	{
		Mat _temp,_tempresy,_tempresx,kern;
		CImage2Mat(_temp,img);
		Mat2CImage(_temp,imgprv[_pic]);
		kern = (Mat_<char>(3,3) << -1, -2, -1,
			0, 0, 0,
			1, 2, 1);
		_tempresx.create(_temp.rows,_temp.cols,_temp.type());
		filter2D(_temp,_tempresx,_temp.depth(),kern);


		kern = (Mat_<char>(3,3) << -1, 0, 1,
			-2, 0, 2,
			-1, 0, 1);

		_tempresy.create(_temp.rows,_temp.cols,_temp.type());
		filter2D(_temp,_tempresy,_temp.depth(),kern);

		_temp = _tempresx + _tempresy ;

		Mat2CImage(_temp,img);
		UpdateAllViews(0); _pic ++;
	}

	void CMFCSDIDoc::OnFuzzyEdge()
	{
		Mat _temp;
		CImage2Mat(_temp,img);
		Mat2CImage(_temp,imgprv[_pic]);
		int dims = 3 ;
		float uwhite [256] = {};
		float ublack [256] = {};
		float uzero [256] = {};
		int zerolimit = 40;
		int limity = _temp.rows - dims;
		int limitx = _temp.cols - dims;
		for(int i = 60 ; i<256 ; i++)
			uwhite[i] = float(float(float(i)/196) - 0.306 );
		for(int i = 0  ; i<196 ; i++)
			ublack[i] = float(1 - float(float(i)/196) );
		for(int i = 0  ; i<zerolimit ; i++)
			uzero[i] = float(1 - float(float(i)/zerolimit) );
		// ***** Priamry values are assigned ... ********
		for ( int j =0 ; j < limity ; j++)
			for ( int i = 0 ; i < limitx ;i++)
			{
				int d[10] = {};
				Mat sub(_temp,Rect(i,j,dims,dims));
				uchar *prev = sub.ptr<uchar>(0) ; 
				uchar *crnt = sub.ptr<uchar>(1) ; 
				uchar *next = sub.ptr<uchar>(2) ; 	

				d[2] = prev[1] - crnt[1];
				d[4] = crnt[0] - crnt[1];
				d[6] = crnt[2] - crnt[1];
				d[8] = next[1] - crnt[1];

				float num = 0;
				float denum =0 ;
				float spd = 0 ;
				if((abs(d[2]) <= zerolimit) && (abs(d[6])<=zerolimit)) 
					for(int r = 60 ; r< 256 ; r++)
					{
						spd = min(uwhite[r] , uzero[d[2]]);
						denum += spd;
						num   += r*spd;
					}

				else if((abs(d[8]) <= zerolimit) && (abs(d[6])<=zerolimit)) 
					for(int r = 60 ; r< 256 ; r++)
					{
						spd = min(uwhite[r] , uzero[d[8]]);
						denum += spd;
						num   += r*spd;
					}


				else if((abs(d[8]) <= zerolimit) && (abs(d[4])<=zerolimit)) 
					for(int r = 60 ; r< 256 ; r++)
					{
						spd = min(uwhite[r] , uzero[d[4]]);
						denum += spd;
						num   += r*spd;
					}


				else if((abs(d[2]) <= zerolimit) && (abs(d[4])<=zerolimit)) 
					for(int r = 60 ; r< 256 ; r++)
					{
						spd = min(uwhite[r] , uzero[d[2]]);
						denum += spd;
						num   += r*spd;
					}

					crnt[1] = num/denum ;		
			}


			Mat2CImage(_temp,img);
			UpdateAllViews(0); _pic ++;
	}

	void CMFCSDIDoc::zweix()
	{
		fact =2*fact;
	}

	void CMFCSDIDoc::vierx()
	{
		fact = 4*fact;
	}

	void CMFCSDIDoc::minus()
	{fact = fact * (-1);
	}

	void CMFCSDIDoc::ein()
	{fact = 1;
	}

	void CMFCSDIDoc::OnFuzzyIntensity()
	{
		Mat _temp;
		CImage2Mat(_temp,img);
		Mat2CImage(_temp,imgprv[_pic]);
		int vd = 45 , vg = 127 , vb = 240 ;
		float udark[256] = {};
		float ugray[256] = {};
		float ubright[256] = {};
		for( int i = 0 ; i < 62 ; i++ )
			udark[i] = 1 ; 
		for( int i = 62 ; i < 127 ; i++)
		{
			udark[i] = float (float(1.954) - float(float(i)/65));
			ugray[i] = float(float(float(i)/65) - float(0.953));
		}
		for(int i = 127 ; i<192 ; i++)
		{
			ugray[i] = float( float(2.984) - float(float(i)/65));
			ubright[i] = float(float(float(i)/65) - float(1.953));
		}
		for(int i = 192 ; i<256 ; i++)
			ubright[i] = 1;
		// ************ End of input membership function **************
		int nc = _temp.channels();
		int limity = _temp.rows ;
		int limitx = _temp.cols*nc ;

		for(int j =0 ; j<limity ; j++)
		{ 
			uchar* data = _temp.ptr<uchar>(j);
			for(int i =0 ; i< limitx ; i++)
			{
				float num = float( udark[data[i]]*vd +  ugray[data[i]]*vg +  ubright[data[i]]*vb );
				float denum =  udark[data[i]] +  ugray[data[i]] +  ubright[data[i]] ;
				data[i] = float( num/denum );
			}
		}

		Mat2CImage(_temp,img);
		UpdateAllViews(0); _pic ++;
	}

	void CMFCSDIDoc::OnEnhancementGamma()
	{
		Mat _temp  ,_tempres;
		CImage2Mat(_temp,img);
		Mat2CImage(_temp,imgprv[_pic]);
		int nl = _temp.rows;
		int nc = (_temp.cols)*(_temp.channels()) ;
		_tempres.create(nl,_temp.cols,_temp.type());
		float _fct = 20/abs(fact) ;
		for(int j = 0 ; j < (nl); j ++)
		{
			uchar* _datares = _tempres.ptr<uchar>(j);
			uchar* _data = _temp.ptr<uchar>(j);
			for ( int i=0 ; i < nc ;i++)
			{
				float tmp = _data[i];
				if(fact >= 1)
					tmp  =  float(pow((tmp/255),float(_fct)));
				if(fact <= -1)
					tmp  =  float(pow((tmp/255),float(1/_fct)));
				_datares[i]  = 255*tmp;
			}
		}
		Mat2CImage(_tempres,img);
		UpdateAllViews(0); _pic ++;
	}

	void CMFCSDIDoc::OnEnhancementLinear()
	{
		Mat _temp  ,_tempres;
		CImage2Mat(_temp,img);
		Mat2CImage(_temp,imgprv[_pic]);
		int nl = _temp.rows;
		int nc = (_temp.cols)*(_temp.channels()) ;
		_tempres.create(nl,_temp.cols,_temp.type());

		// ********************* Assigning input parameters *********************
		float r1 =100 , r2 =180 ;
		float s1 =40 , s2 =120 ;
		// ********************* Assigning input parameters *********************


		for(int j = 0 ; j < (nl); j ++)
		{
			uchar* _datares = _tempres.ptr<uchar>(j);
			uchar* _data = _temp.ptr<uchar>(j);
			for ( int i=0 ; i < nc ;i++)
			{
				if(_data[i] <= r1)
					_datares[i] = _data[i]*float(s1/r1) ;

				else if(r1 < _data[i] <= r2)
					_datares[i] = s2 + (_data[i] - r2)*float((s2-s1)/(r2-r1)) ;

				else if(r2 < _data[i])
					_datares[i] = 255 + (_data[i] - 255)*float((255-s2)/(255 - r2)) ;


			}
		}
		Mat2CImage(_tempres,img);
		UpdateAllViews(0); _pic ++;
	}

	void CMFCSDIDoc::OnAliasingChessboard()
	{
		Mat _temp;
		Mat _tempres ;
		CImage2Mat(_temp,img);
		Mat2CImage(_temp,imgprv[_pic]);
		int chess = (2*fact+1) ;
		int limity = _temp.rows - chess ;
		int limitx = _temp.cols - chess ;
		_tempres = Mat::zeros(_temp.rows/chess,_temp.cols/chess,_temp.type());
		for(int j =0 ; j<limity;)
		{
			for(int i =0 ; i< limitx ;)
			{
				Mat sub(_temp,Rect(i,j,chess,chess));
				uchar *data = sub.ptr<uchar>(chess/2);
				uchar *datares = _tempres.ptr<uchar>(j/chess);
				datares[i/chess] = data[chess/2];
				i += chess;
			}
			j = j+chess;
		}
		//********************* A PROTOTYPE CHESS BOARD **************
		/*
		Mat _temp =  Mat::zeros(2048,2048, CV_8UC1);
		int nl = _temp.rows;
		int nc = _temp.cols*_temp.channels();
		int chess = (16);
		int limity = nl ;
		int limitx = nc ;
		for(int j= 0 ; j<limity ; j++)
		for(int i =0 ; i<limitx ;i++)
		{
		uchar *data = _temp.ptr<uchar>(j);
		if((j/chess)%2 == 0)
		if((i/chess)%2 == 1)
		data[i] = 255;
		if((j/chess)%2 == 1)
		if((i/chess)%2 == 0)
		data[i] = 255;

		}
		imwrite("CHESS.jpg",_temp);
		*/
		//************ END OF MAKING A CHESS BOARD ***************

		Mat2CImage(_tempres,img);
		UpdateAllViews(0); _pic ++;
	}

	void CMFCSDIDoc::OnFrquencyLowpassfilter32814()
	{
		//Guassian 

		Mat J;
		CImage2Mat(J,img);
		Mat2CImage(J,imgprv[_pic]);
		if(J.step[1] == 3)
			cvtColor( J, J, CV_BGR2GRAY );
		J.convertTo(J, CV_32F);
		Mat paddedJ;                            //expand input image to optimal size
		int m = getOptimalDFTSize( J.rows );
		int n = getOptimalDFTSize( J.cols ); // on the border add zero values
		copyMakeBorder(J, paddedJ, 0, m - J.rows, 0, n - J.cols, BORDER_CONSTANT, Scalar::all(0));
		Mat planesJ[] = {Mat_<float>(paddedJ), Mat::zeros(paddedJ.size(), CV_32F)}; 
		Mat complexJ;
		merge(planesJ, 2, complexJ);         // Add to the expanded another plane with zeros
		dft(complexJ, complexJ , cv::DFT_SCALE|cv::DFT_COMPLEX_OUTPUT);            // this way the result may fit in the source matrix
		split(complexJ, planesJ);                   // planes[0] = Re(DFT(I), planes[1] = Im(DFT(I))
		Mat magJ ,phasJ;
		magnitude(planesJ[0],planesJ[1],magJ);
		phase(planesJ[0],planesJ[1],phasJ);
		int cx = magJ.cols/2;
		int cy = magJ.rows/2;
		Mat q0(magJ, Rect(0, 0, cx, cy));
		Mat q1(magJ, Rect(cx, 0, cx, cy));
		Mat q2(magJ, Rect(0, cy, cx, cy));
		Mat q3(magJ, Rect(cx, cy, cx, cy));
		Mat tmp;
		q0.copyTo(tmp);
		q3.copyTo(q0);
		tmp.copyTo(q3);
		q1.copyTo(tmp);
		q2.copyTo(q1);
		tmp.copyTo(q2);

		//************ END OF FRQ ACQUISITION AND SHIFT *************
		//******** BEGINING OF FILTER DEFINITION *********************************


		Mat H;
		H = Mat::zeros(magJ.rows,magJ.cols,CV_8UC1);
		int dims = 10*fact;
		int limity = H.rows;//(cy+dims);
		int limitx = H.cols;//nc*(cx+dims);
		int starty = 0;//(cy-dims);
		int startx = 0;//nc*(cx-dims);
		float den = float((-0.5)/float(pow(float(dims),2)));
		for(int j=starty;j<limity;j++)
		{uchar *filter = H.ptr<uchar>(j);
		for(int i=startx;i<limitx;i++)
		{
			float num = float(pow(float(i-cx),2) + pow(float(j-cy),2));
			num =  float(exp(float(num*den)));
			filter[i]  = 255*num ;
		}
		}
		H = 255 - H;
		imwrite("filt.jpg",H);
		H.convertTo(H,magJ.type());
		//******** END OF FILTER *********************************
		multiply(magJ,H,magJ);
		magJ = magJ / 255 ;
		Mat q5(magJ, Rect(0, 0, cx, cy));
		Mat q6(magJ, Rect(cx, 0, cx, cy));
		Mat q7(magJ, Rect(0, cy, cx, cy));
		Mat q8(magJ, Rect(cx, cy, cx, cy));
		tmp;
		q0.copyTo(tmp);
		q3.copyTo(q0);
		tmp.copyTo(q3);
		q1.copyTo(tmp);
		q2.copyTo(q1);
		tmp.copyTo(q2);
		//***************** END OF MAG OPERATIONS **************

		/*log(magJ,magJ);
		normalize(magJ, magJ, 0, 1, CV_MINMAX);
		magJ = magJ*256;
		imwrite("filt.jpg",magJ);
		*/
		Mat planesO[2];
		Mat complexO;
		polarToCart(magJ,phasJ,planesO[0],planesO[1]);
		merge(planesO,2,complexO);
		dft(complexO,complexO,cv::DFT_INVERSE);
		split(complexO,planesO);
		planesO[0].convertTo(planesO[0],CV_8UC1);
		Mat2CImage(planesO[0],img);
		UpdateAllViews(0); _pic ++;
	}	

	void CMFCSDIDoc::OnFrquencyLowpassfilter32815()
	{
		//butterworth 

		Mat J;
		CImage2Mat(J,img);
		Mat2CImage(J,imgprv[_pic]);
		if(J.step[1] == 3)
			cvtColor( J, J, CV_BGR2GRAY );
		J.convertTo(J, CV_32F);
		Mat paddedJ;                            //expand input image to optimal size
		int m = getOptimalDFTSize( J.rows );
		int n = getOptimalDFTSize( J.cols ); // on the border add zero values
		copyMakeBorder(J, paddedJ, 0, m - J.rows, 0, n - J.cols, BORDER_CONSTANT, Scalar::all(0));
		Mat planesJ[] = {Mat_<float>(paddedJ), Mat::zeros(paddedJ.size(), CV_32F)}; 
		Mat complexJ;
		merge(planesJ, 2, complexJ);         // Add to the expanded another plane with zeros
		dft(complexJ, complexJ , cv::DFT_SCALE|cv::DFT_COMPLEX_OUTPUT);            // this way the result may fit in the source matrix
		split(complexJ, planesJ);                   // planes[0] = Re(DFT(I), planes[1] = Im(DFT(I))
		Mat magJ ,phasJ;
		magnitude(planesJ[0],planesJ[1],magJ);
		phase(planesJ[0],planesJ[1],phasJ);
		int cx = magJ.cols/2;
		int cy = magJ.rows/2;
		Mat q0(magJ, Rect(0, 0, cx, cy));
		Mat q1(magJ, Rect(cx, 0, cx, cy));
		Mat q2(magJ, Rect(0, cy, cx, cy));
		Mat q3(magJ, Rect(cx, cy, cx, cy));
		Mat tmp;
		q0.copyTo(tmp);
		q3.copyTo(q0);
		tmp.copyTo(q3);
		q1.copyTo(tmp);
		q2.copyTo(q1);
		tmp.copyTo(q2);

		//************ END OF FRQ ACQUISITION AND SHIFT *************
		//******** BEGINING OF FILTER DEFINITION *********************************


		Mat H;
		H = Mat::zeros(magJ.rows,magJ.cols,CV_8UC1);
		int dims = 10*fact;
		if(dims < min(cy,cx)) {
			int _n = 1;
			int limity = H.rows;
			int limitx = H.cols;
			int starty = 0;
			int startx = 0;
			for(int j=starty;j<limity;j++)
			{uchar *filter = H.ptr<uchar>(j);
			for(int i=startx;i<limitx;i++)
			{
				float num = sqrt(float(pow(float(i-cx),2) + pow(float(j-cy),2)));
				num = 1/(1 +  float(pow(float(num/dims),2*_n)));
				filter[i]  = 255*num ;
			}
			}
			imwrite("filt.jpg",H);
			H.convertTo(H,magJ.type());
			//******** END OF FILTER *********************************
			multiply(magJ,H,magJ);
			magJ = magJ / 255 ;
			Mat q5(magJ, Rect(0, 0, cx, cy));
			Mat q6(magJ, Rect(cx, 0, cx, cy));
			Mat q7(magJ, Rect(0, cy, cx, cy));
			Mat q8(magJ, Rect(cx, cy, cx, cy));
			tmp;
			q0.copyTo(tmp);
			q3.copyTo(q0);
			tmp.copyTo(q3);
			q1.copyTo(tmp);
			q2.copyTo(q1);
			tmp.copyTo(q2);
			//***************** END OF MAG OPERATIONS **************
			Mat planesO[2];
			Mat complexO;
			polarToCart(magJ,phasJ,planesO[0],planesO[1]);
			merge(planesO,2,complexO);
			dft(complexO,complexO,cv::DFT_INVERSE);
			split(complexO,planesO);
			planesO[0].convertTo(planesO[0],CV_8UC1);
			Mat2CImage(planesO[0],img);
		}
		else 
		{
			//MessageBox(this,_T("dim is much bigger than expected"));
		}
		UpdateAllViews(0); _pic ++;
	}

	void CMFCSDIDoc::OnFrquencyHomomorphic()
	{
		Mat J;
		CImage2Mat(J,img);
		Mat2CImage(J,imgprv[_pic]);
		if(J.step[1]==3)
			cvtColor( J, J, CV_BGR2GRAY );
		J.convertTo(J, CV_32F);
		J += 1;
		log(J,J);

		//normalize(J,J, 0, 1, CV_MINMAX);
		//J = J*255;

		Mat paddedJ;                            //expand input image to optimal size
		int m = getOptimalDFTSize( J.rows );
		int n = getOptimalDFTSize( J.cols ); // on the border add zero values
		copyMakeBorder(J, paddedJ, 0, m - J.rows, 0, n - J.cols, BORDER_CONSTANT, Scalar::all(0));
		Mat planesJ[] = {Mat_<float>(paddedJ), Mat::zeros(paddedJ.size(), CV_32F)}; 
		Mat complexJ;
		merge(planesJ, 2, complexJ);         // Add to the expanded another plane with zeros
		dft(complexJ, complexJ , cv::DFT_SCALE|cv::DFT_COMPLEX_OUTPUT);            // this way the result may fit in the source matrix
		split(complexJ, planesJ);                   // planes[0] = Re(DFT(I), planes[1] = Im(DFT(I))
		Mat magJ ,phasJ;
		magnitude(planesJ[0],planesJ[1],magJ);
		phase(planesJ[0],planesJ[1],phasJ);
		int cx = magJ.cols/2;
		int cy = magJ.rows/2;
		Mat q0(magJ, Rect(0, 0, cx, cy));
		Mat q1(magJ, Rect(cx, 0, cx, cy));
		Mat q2(magJ, Rect(0, cy, cx, cy));
		Mat q3(magJ, Rect(cx, cy, cx, cy));
		Mat tmp;
		q0.copyTo(tmp);
		q3.copyTo(q0);
		tmp.copyTo(q3);
		q1.copyTo(tmp);
		q2.copyTo(q1);
		tmp.copyTo(q2);


		//************ END OF FRQ ACQUISITION AND SHIFT *************
		//******** BEGINING OF FILTER DEFINITION *********************************

		Mat H;
		H = Mat::zeros(magJ.rows,magJ.cols,CV_8UC1);
		int dims = 80;//10*fact;
		int limity = H.rows;//(cy+dims);
		int limitx = H.cols;//nc*(cx+dims);
		int starty = 0;//(cy-dims);
		int startx = 0;//nc*(cx-dims);
		float den = 65532*float((-0.5)/float(pow(float(dims),2)));
		for(int j=starty;j<limity;j++)
		{uchar *filter = H.ptr<uchar>(j);
		for(int i=startx;i<limitx;i++)
		{
			float num = 0.00015*float(pow(float(i-cx),2) + pow(float(j-cy),2));
			num =  float(exp(float(num*den)));
			filter[i]  = 255*num ;
		}
		}
		H = 255 - H ;
		H += 255*0.125 ;
		imwrite("filt.jpg",H);
		H.convertTo(H,magJ.type());

		//******** END OF FILTER ***********ii**********************
		Mat prm;
		multiply(magJ,H,prm);
		prm = prm / 255 ;
		magJ += prm;

		Mat q5(magJ, Rect(0, 0, cx, cy));
		Mat q6(magJ, Rect(cx, 0, cx, cy));
		Mat q7(magJ, Rect(0, cy, cx, cy));
		Mat q8(magJ, Rect(cx, cy, cx, cy));
		tmp;
		q0.copyTo(tmp);
		q3.copyTo(q0);
		tmp.copyTo(q3);
		q1.copyTo(tmp);
		q2.copyTo(q1);
		tmp.copyTo(q2);
		//***************** END OF MAG OPERATIONS **************

		Mat planesO[2];
		Mat complexO;
		polarToCart(magJ,phasJ,planesO[0],planesO[1]);
		merge(planesO,2,complexO);
		dft(complexO,complexO,cv::DFT_INVERSE);
		split(complexO,planesO);

		exp(planesO[0],planesO[0]);

		planesO[0].convertTo(planesO[0],CV_8UC1);
		Mat2CImage(planesO[0],img);
		UpdateAllViews(0); _pic ++;

	}

	void CMFCSDIDoc::OnFrquencyLaplacian()
	{
		Mat J;
		CImage2Mat(J,img);
		Mat2CImage(J,imgprv[_pic]);
		if(J.step[1] == 3)
			cvtColor( J, J, CV_BGR2GRAY );
		J.convertTo(J, CV_32F);
		Mat paddedJ;                            //expand input image to optimal size
		int m = getOptimalDFTSize( J.rows );
		int n = getOptimalDFTSize( J.cols ); // on the border add zero values
		copyMakeBorder(J, paddedJ, 0, m - J.rows, 0, n - J.cols, BORDER_CONSTANT, Scalar::all(0));
		Mat planesJ[] = {Mat_<float>(paddedJ), Mat::zeros(paddedJ.size(), CV_32F)}; 
		Mat complexJ;
		merge(planesJ, 2, complexJ);         // Add to the expanded another plane with zeros
		dft(complexJ, complexJ , cv::DFT_SCALE|cv::DFT_COMPLEX_OUTPUT);            // this way the result may fit in the source matrix
		split(complexJ, planesJ);                   // planes[0] = Re(DFT(I), planes[1] = Im(DFT(I))
		Mat magJ ,phasJ;
		magnitude(planesJ[0],planesJ[1],magJ);
		phase(planesJ[0],planesJ[1],phasJ);
		int cx = magJ.cols/2;
		int cy = magJ.rows/2;
		Mat q0(magJ, Rect(0, 0, cx, cy));
		Mat q1(magJ, Rect(cx, 0, cx, cy));
		Mat q2(magJ, Rect(0, cy, cx, cy));
		Mat q3(magJ, Rect(cx, cy, cx, cy));
		Mat tmp;
		q0.copyTo(tmp);
		q3.copyTo(q0);
		tmp.copyTo(q3);
		q1.copyTo(tmp);
		q2.copyTo(q1);
		tmp.copyTo(q2);

		//************ END OF FRQ ACQUISITION AND SHIFT *************
		//******** BEGINING OF FILTER DEFINITION *********************************


		Mat H;
		H = Mat::zeros(magJ.rows,magJ.cols,CV_8UC1);
		int dims = 5*fact + (magJ.cols*magJ.rows/10000) ;
		int _n = 1;
		int limity = H.rows;//(cy+dims);
		int limitx = H.cols;//(cx+dims);
		int starty = 0;//(cy-dims);
		int startx = 0;// (cx-dims);
		float den = 65532*float((-0.5)/float(pow(float(dims),2)));
		for(int j=starty;j<limity;j++)
		{uchar *filter = H.ptr<uchar>(j);
		for(int i=startx;i<limitx;i++)
		{
			float num = 0.00015*float(pow(float(i-cx),2) + pow(float(j-cy),2));
			num =  float(exp(float(num/den)));
			filter[i] = 255*num;
		}
		}
		H = 255 - H;
		H.convertTo(H,magJ.type());
		//******** END OF FILTER *********************************
		multiply(magJ,H,magJ);
		magJ = magJ/255;
		Mat q5(magJ, Rect(0, 0, cx, cy));
		Mat q6(magJ, Rect(cx, 0, cx, cy));
		Mat q7(magJ, Rect(0, cy, cx, cy));
		Mat q8(magJ, Rect(cx, cy, cx, cy));
		tmp;
		q0.copyTo(tmp);
		q3.copyTo(q0);
		tmp.copyTo(q3);
		q1.copyTo(tmp);
		q2.copyTo(q1);
		tmp.copyTo(q2);
		//***************** END OF MAG OPERATIONS **************
		Mat planesO[2];
		Mat complexO;
		polarToCart(magJ,phasJ,planesO[0],planesO[1]);
		merge(planesO,2,complexO);
		dft(complexO,complexO,cv::DFT_INVERSE);
		split(complexO,planesO);
		planesO[0].convertTo(planesO[0],CV_8UC1);
		Mat2CImage(planesO[0],img);
		UpdateAllViews(0); _pic ++;

	}

	void CMFCSDIDoc::OnFrquencyRotate()
	{
		Mat J;
		CImage2Mat(J,img);
		Mat2CImage(J,imgprv[_pic]);
		Point2f src_center(J.cols/2.0F, J.rows/2.0F);
		Mat rot_mat = getRotationMatrix2D(src_center, fact*18, 1.0);
		warpAffine(J, J, rot_mat, J.size());
		if(J.step[1] == 3)
			cvtColor( J, J, CV_BGR2GRAY );
		J.convertTo(J, CV_32F);
		Mat paddedJ;                            //expand input image to optimal size
		int m = getOptimalDFTSize( J.rows );
		int n = getOptimalDFTSize( J.cols ); // on the border add zero values
		copyMakeBorder(J, paddedJ, 0, m - J.rows, 0, n - J.cols, BORDER_CONSTANT, Scalar::all(0));
		Mat planesJ[] = {Mat_<float>(paddedJ), Mat::zeros(paddedJ.size(), CV_32F)}; 
		Mat complexJ;
		merge(planesJ, 2, complexJ);         // Add to the expanded another plane with zeros
		dft(complexJ, complexJ , cv::DFT_SCALE|cv::DFT_COMPLEX_OUTPUT);            // this way the result may fit in the source matrix
		split(complexJ, planesJ);                   // planes[0] = Re(DFT(I), planes[1] = Im(DFT(I))
		Mat magJ ,phasJ;
		magnitude(planesJ[0],planesJ[1],magJ);
		phase(planesJ[0],planesJ[1],phasJ);
		int cx = magJ.cols/2;
		int cy = magJ.rows/2;
		Mat q0(magJ, Rect(0, 0, cx, cy));
		Mat q1(magJ, Rect(cx, 0, cx, cy));
		Mat q2(magJ, Rect(0, cy, cx, cy));
		Mat q3(magJ, Rect(cx, cy, cx, cy));
		Mat tmp;
		q0.copyTo(tmp);
		q3.copyTo(q0);
		tmp.copyTo(q3);
		q1.copyTo(tmp);
		q2.copyTo(q1);
		tmp.copyTo(q2);

		log(magJ,magJ);
		normalize(magJ, magJ, 0, 1, CV_MINMAX);
		magJ = magJ*256;
		magJ.convertTo(magJ,CV_8UC1);
		Mat2CImage(magJ,img);
		UpdateAllViews(0); _pic ++;

	}

	void CMFCSDIDoc::OnFrquencyCorelation()
	{
		Mat J;
		CImage2Mat(J,img);
		Mat2CImage(J,imgprv[_pic]);
		if(J.step[1] == 3)
			cvtColor( J, J, CV_BGR2GRAY );
		J.convertTo(J, CV_32F);
		Mat paddedJ;                            //expand input image to optimal size
		int m = getOptimalDFTSize( J.rows );
		int n = getOptimalDFTSize( J.cols ); // on the border add zero values
		copyMakeBorder(J, paddedJ, 0, m - J.rows, 0, n - J.cols, BORDER_CONSTANT, Scalar::all(0));
		Mat planesJ[] = {Mat_<float>(paddedJ), Mat::zeros(paddedJ.size(), CV_32F)}; 
		Mat complexJ;
		merge(planesJ, 2, complexJ);         // Add to the expanded another plane with zeros
		dft(complexJ, complexJ , cv::DFT_SCALE|cv::DFT_COMPLEX_OUTPUT);            // this way the result may fit in the source matrix
		split(complexJ, planesJ);                   // planes[0] = Re(DFT(I), planes[1] = Im(DFT(I))
		planesJ[1] = planesJ[1]*(-1); // conjugate
		merge(planesJ,2,complexJ);
		// **** Model input ****
		CImage tempI;
		Mat I;
		savebox Dlg;
t1:
		Dlg.DoModal();
		if(Dlg._Sflag)
			tempI.Load(Dlg.m_savebrowseval);
		if(tempI.IsNull())
		{	
			goto t1;
		}
		CImage2Mat(I,tempI);
		if(I.step[1] == 3)
			cvtColor( I, I, CV_BGR2GRAY );
		I.convertTo(I, CV_32F);
		Mat paddedI;                            //expand input image to optimal size
		m = getOptimalDFTSize( I.rows );
		n = getOptimalDFTSize( I.cols ); // on the border add zero values
		copyMakeBorder(I, paddedI, 0, m - I.rows, 0, n - I.cols, BORDER_CONSTANT, Scalar::all(0));
		Mat planesI[] = {Mat_<float>(paddedI), Mat::zeros(paddedI.size(), CV_32F)}; 
		Mat complexI;
		merge(planesI, 2, complexI);         // Add to the expanded another plane with zeros
		dft(complexI, complexI , cv::DFT_SCALE|cv::DFT_COMPLEX_OUTPUT);            // this way the result may fit in the source matrix
		split(complexI, planesI);                   // planes[0] = Re(DFT(I), planes[1] = Im(DFT(I))
		multiply(complexI,complexJ,complexJ);

		dft(complexJ,complexJ,cv::DFT_INVERSE);
		split(complexJ,planesJ);
		planesJ[0].convertTo(planesJ[0],CV_8UC1);

		int max[3] = {} ;
		for(int j=0;j<planesJ[0].rows;j++)
		{	uchar *data = planesJ[0].ptr<uchar>(j);
		for(int i=0 ; i<planesJ[0].step ; i++)
			if(data[i] > max[0]) {max[0]=data[i];max[1]=i;max[2]=j;} 
		}


		Report Dlgp;
		char str[10];
		CString print ;
		itoa(max[1],str,10);
		print = L"x=";
		print += str;
		print += L"  ";
		itoa(max[2],str,10);
		print += L"y=";
		print += str;
		print += L"  ";
		Dlgp.m_reportedit = print;
		Dlgp.DoModal();


		Mat2CImage(planesJ[0],img);
		UpdateAllViews(0); _pic ++;
	}

	void CMFCSDIDoc::OnEnhancementGeometric()
	{
		Mat mat (img.GetHeight() , img.GetWidth() , CV_8UC3); 
		Mat matres ;
		int m_sliderval = 2;
		CImage2Mat(mat,img);

		if(mat.step[1] == 3)
			cvtColor( mat, mat, CV_BGR2GRAY );

		Mat2CImage(mat,imgprv[_pic]);
		int nl = mat.rows;
		int nc = mat.cols;
		int limity = nl -1 ;
		int limitx = nc -1 ;
		matres = Mat::zeros(nl,nc,mat.type());
		for(int j=1 ; j < limity ; j++)
		{
			uchar* datares = matres.ptr<uchar>(j);
			uchar* dataprv = mat.ptr<uchar>(j-1);
			uchar* datacrt = mat.ptr<uchar>(j);
			uchar* datanxt = mat.ptr<uchar>(j+1);

			for(int i = 1 ; i<limitx ;i++)
			{
				double tmp1 = pow(double(dataprv[i-1]*dataprv[i]*dataprv[i+1]),0.111);
				double tmp2 = pow(double(datanxt[i-1]*datanxt[i]*datanxt[i+1]),0.111);
				double tmp3 = pow(double(datacrt[i-1]*datacrt[i])*datacrt[i+1],0.111);
				datares[i] = tmp1*tmp2*tmp3;
			}
		}
		imwrite("test.jpg",matres);
		Mat2CImage(matres,img);
		UpdateAllViews(0); _pic ++;
	}

	void CMFCSDIDoc::OnEnhancementArithmean()
	{
		Mat mat (img.GetHeight() , img.GetWidth() , CV_8UC3); 
		Mat matres ;
		int m_sliderval = 2;
		CImage2Mat(mat,img);

		if(mat.step[1] == 3)
			cvtColor( mat, mat, CV_BGR2GRAY );

		Mat2CImage(mat,imgprv[_pic]);
		int nl = mat.rows;
		int nc = mat.cols;
		int limity = nl -1 ;
		int limitx = nc -1 ;
		matres = Mat::zeros(nl,nc,mat.type());
		for(int j=1 ; j < limity ; j++)
		{
			uchar* datares = matres.ptr<uchar>(j);
			uchar* dataprv = mat.ptr<uchar>(j-1);
			uchar* datacrt = mat.ptr<uchar>(j);
			uchar* datanxt = mat.ptr<uchar>(j+1);

			for(int i = 1 ; i<limitx ;i++)
			{
				double tmp1 = double(dataprv[i-1]+dataprv[i]+dataprv[i+1]);
				double tmp2 = double(datanxt[i-1]+datanxt[i]+datanxt[i+1]);
				double tmp3 = double(datacrt[i-1]+datacrt[i]+datacrt[i+1]);
				datares[i] = (tmp1+tmp2+tmp3)/9;
			}
		}
		imwrite("test.jpg",matres);
		Mat2CImage(matres,img);
		UpdateAllViews(0); _pic ++;

	}

	void CMFCSDIDoc::OnEnhancementAdaptivemedian()
	{
		Mat _temp;
		CImage2Mat(_temp,img);
		Mat2CImage(_temp,imgprv[_pic]);

		if(_temp.step[1] == 3)
			cvtColor( _temp,_temp, CV_BGR2GRAY );

		Mat _tempres = Mat::zeros(_temp.rows,_temp.cols,_temp.type());

		int dimensmax = 10;
		int dimensmin = 2*(fact)+1;
		int dimens = dimensmin;

		int limitx = (_temp.cols - dimensmax) ;
		int limity = (_temp.rows - dimensmax) ; 

		for(int j =0; j< limity ; j++)
		{
			uchar* _datares = _tempres.ptr<uchar>(j);
			uchar* _datasrc = _temp.ptr<uchar>(j);
			for(int i =0; i < limitx ;i++)
			{
t1:
				int median = (int((dimens*dimens)/2)) ;
				int min = (dimens*dimens-1);
				int max = 0;

				int *vect = new int [dimens*dimens];
				Mat sub(_temp,Rect(i,j,dimens,dimens));
				for(int k = 0 ; k < dimens ; k ++)
				{
					uchar* _data = sub.ptr<uchar>(k);
					for(int l = 0 ; l < dimens ; l++)
						vect[k*dimens + l] = _data[l] ;
				}

				sort(vect,(dimens*dimens));
				int A1 = vect[median] - vect[min];
				int A2 = vect[median] - vect[max] ;
				if((A1>0)&&(A2<0)) 
				{
					if(((_datasrc[i]-vect[min])>0)&&((_datasrc[i]-vect[max])<0))
						_datares[i] = _datasrc[i];
					else
						_datares[i] = vect[median];
					dimens = dimensmin;
				}

				else
				{
					dimens += 1 ; 
					if(dimens >= dimensmax)
					{
						dimens = dimensmin ;
						_datares[i] = vect[median];
					}
					else
						goto t1;

				}

				delete(vect);
			}
		}
		Mat2CImage(_tempres,img);
		UpdateAllViews(0); _pic ++;
	}

	void CMFCSDIDoc::OnEnhancementContraharmonic()
	{
		Mat mat (img.GetHeight() , img.GetWidth() , CV_8UC3); 
		Mat matres ;
		int m_sliderval = 2;
		CImage2Mat(mat,img);

		if(mat.step[1] == 3)
			cvtColor( mat, mat, CV_BGR2GRAY );

		Mat2CImage(mat,imgprv[_pic]);
		int nl = mat.rows;
		int nc = mat.cols;
		int limity = nl -1 ;
		int limitx = nc -1 ;
		matres = Mat::zeros(nl,nc,mat.type());

		for(int j=1 ; j < limity ; j++)
		{
			uchar* datares = matres.ptr<uchar>(j);
			uchar* dataprv = mat.ptr<uchar>(j-1);
			uchar* datacrt = mat.ptr<uchar>(j);
			uchar* datanxt = mat.ptr<uchar>(j+1);

			for(int i = 1 ; i<limitx ;i++)
			{
				double tmp1 = double(pow(float(dataprv[i-1]),float(fact+1))+pow(float(dataprv[i]),float(fact+1))+pow(float(dataprv[i+1]),float(fact+1)));
				tmp1 += double(pow(float(datanxt[i-1]),float(fact+1))+pow(float(datanxt[i]),float(fact+1))+pow(float(datanxt[i+1]),float(fact+1)));
				tmp1 += double(pow(float(datacrt[i-1]),float(fact+1))+pow(float(datacrt[i]),float(fact+1))+pow(float(datacrt[i+1]),float(fact+1)));

				double tmp2 = double(pow(float(dataprv[i-1]),float(fact))+pow(float(dataprv[i]),float(fact))+pow(float(dataprv[i+1]),float(fact)));
				tmp2 += double(pow(float(datanxt[i-1]),float(fact))+pow(float(datanxt[i]),float(fact))+pow(float(datanxt[i+1]),float(fact)));
				tmp2 += double(pow(float(datacrt[i-1]),float(fact))+pow(float(datacrt[i]),float(fact))+pow(float(datacrt[i+1]),float(fact)));

				datares[i] = (tmp1)/(tmp2);
			}
		}
		Mat2CImage(matres,img);
		UpdateAllViews(0); _pic ++;
	}

	void CMFCSDIDoc::OnEnhancementMidpoi()
	{
		Mat _temp;
		CImage2Mat(_temp,img);
		Mat2CImage(_temp,imgprv[_pic]);

		if(_temp.step[1] == 3)
			cvtColor( _temp,_temp, CV_BGR2GRAY );

		Mat _tempres = Mat::zeros(_temp.rows,_temp.cols,_temp.type());
		int dimens = 3;//3*fact;
		int limitx = (_temp.cols - dimens) ;
		int limity = (_temp.rows - dimens) ; 

		int min = (dimens*dimens-1);
		int max = 0;

		for(int j =(dimens/2); j< limity ; j++)
		{
			uchar* _datares = _tempres.ptr<uchar>(j);
			uchar* _datasrc = _temp.ptr<uchar>(j);
			for(int i =(dimens/2) ; i < limitx ;i++)
			{
				int *vect = new int [dimens*dimens];
				Mat sub(_temp,Rect(i,j,dimens,dimens));
				for(int k = 0 ; k < dimens ; k ++)
				{
					uchar* _data = sub.ptr<uchar>(k);
					for(int l = 0 ; l < dimens ; l++)
						vect[k*dimens + l] = _data[l] ;
				}

				sort(vect,(dimens*dimens));
				_datares[i] = ((vect[max]+vect[min])/2);

				delete(vect);
			}
		}
		Mat2CImage(_tempres,img);
		UpdateAllViews(0); _pic ++;
	}

	void CMFCSDIDoc::OnEnhancementAlpha()
	{
		Mat _temp;
		CImage2Mat(_temp,img);
		Mat2CImage(_temp,imgprv[_pic]);

		if(_temp.step[1] == 3)
			cvtColor( _temp,_temp, CV_BGR2GRAY );

		Mat _tempres = Mat::zeros(_temp.rows,_temp.cols,_temp.type());
		int dimens = 3;//3*fact;
		int limitx = (_temp.cols - dimens) ;
		int limity = (_temp.rows - dimens) ; 

		int min = 0;
		int max = (dimens*dimens-1);

		if((fact > max)||(fact<min))
		{Report Dlgp;
		Dlgp.m_reportedit = "Value for D is incorrect";
		Dlgp.DoModal();
		}

		for(int j =(dimens/2); j< limity ; j++)
		{
			uchar* _datares = _tempres.ptr<uchar>(j);
			uchar* _datasrc = _temp.ptr<uchar>(j);
			for(int i =(dimens/2) ; i < limitx ;i++)
			{
				int *vect = new int [dimens*dimens];
				Mat sub(_temp,Rect(i,j,dimens,dimens));
				for(int k = 0 ; k < dimens ; k ++)
				{
					uchar* _data = sub.ptr<uchar>(k);
					for(int l = 0 ; l < dimens ; l++)
						vect[k*dimens + l] = _data[l] ;
				}

				sort(vect,(dimens*dimens));
				int limit = max -fact/2;
				double prmm =0 ;
				for(int klm =((fact)/2) ; klm <= limit ;klm++)
					prmm += vect[klm] ;

				_datares[i] = prmm /(max-fact+1);

				delete(vect);
			}
		}
		Mat2CImage(_tempres,img);
		UpdateAllViews(0); _pic ++;
	}

	void CMFCSDIDoc::OnEnhancementPeriodicnoise()
	{
		Mat mat (img.GetHeight() , img.GetWidth() , CV_8UC3); 
		Mat matres  ,  noise ;
		int m_sliderval = 2;
		CImage2Mat(mat,img);

		if(mat.step[1] == 3)
			cvtColor( mat, mat, CV_BGR2GRAY );

		Mat2CImage(mat,imgprv[_pic]);
		int nl = mat.rows;
		int nc = mat.cols;
		noise = Mat::zeros(nl,nc,mat.type());
		matres = Mat::zeros(nl,nc,mat.type());
		int chess = 4;

		for(int j =0 ; j<nl ; j++)
			for(int i =0 ; i<nc ;i++)
			{
				uchar *data = noise.ptr<uchar>(j);
				if((j%chess)/2 == 0)
					data[i] = 255;
				if((i%chess)/2 == 0)
					data[i] = 255;
			}
			imwrite("noise.jpg",noise);
			for(int j=0 ; j < nl ; j++)
			{	
				uchar* datares = matres.ptr<uchar>(j);
				uchar* _noise = noise.ptr<uchar>(j);
				uchar* data = mat.ptr<uchar>(j);
				for(int i=0 ; i < nc ; i++)
				{
					datares[i] = ((0.8)*data[i] + (0.2)*_noise[i]);
				}
			}
			Mat2CImage(matres,img);
			UpdateAllViews(0); _pic ++;


	}

	void CMFCSDIDoc::OnFrquencyMagview()
	{
		Mat J;
		CImage2Mat(J,img);
		Mat2CImage(J,imgprv[_pic]);
		if(J.step[1] == 3)
			cvtColor( J, J, CV_BGR2GRAY );
		J.convertTo(J, CV_32F);
		Mat paddedJ;                            //expand input image to optimal size
		int m = getOptimalDFTSize( J.rows );
		int n = getOptimalDFTSize( J.cols ); // on the border add zero values
		copyMakeBorder(J, paddedJ, 0, m - J.rows, 0, n - J.cols, BORDER_CONSTANT, Scalar::all(0));
		Mat planesJ[] = {Mat_<float>(paddedJ), Mat::zeros(paddedJ.size(), CV_32F)}; 
		Mat complexJ;
		merge(planesJ, 2, complexJ);         // Add to the expanded another plane with zeros
		dft(complexJ, complexJ , cv::DFT_SCALE|cv::DFT_COMPLEX_OUTPUT);            // this way the result may fit in the source matrix
		split(complexJ, planesJ);                   // planes[0] = Re(DFT(I), planes[1] = Im(DFT(I))
		Mat magJ ,phasJ;
		magnitude(planesJ[0],planesJ[1],magJ);
		phase(planesJ[0],planesJ[1],phasJ);
		int cx = magJ.cols/2;
		int cy = magJ.rows/2;
		Mat q0(magJ, Rect(0, 0, cx, cy));
		Mat q1(magJ, Rect(cx, 0, cx, cy));
		Mat q2(magJ, Rect(0, cy, cx, cy));
		Mat q3(magJ, Rect(cx, cy, cx, cy));
		Mat tmp;
		q0.copyTo(tmp);
		q3.copyTo(q0);
		tmp.copyTo(q3);
		q1.copyTo(tmp);
		q2.copyTo(q1);
		tmp.copyTo(q2);

		log(magJ,magJ);
		normalize(magJ, magJ, 0, 1, CV_MINMAX);
		magJ = magJ*256;
		magJ.convertTo(magJ,CV_8UC1);
		Mat2CImage(magJ,img);
		UpdateAllViews(0); _pic ++;


	}

	void CMFCSDIDoc::OnEnhancementRingfilter()
	{
		Mat J;
		CImage2Mat(J,img);
		Mat2CImage(J,imgprv[_pic]);
		if(J.step[1] == 3)
			cvtColor( J, J, CV_BGR2GRAY );
		J.convertTo(J, CV_32F);
		Mat paddedJ;                            //expand input image to optimal size
		int m = getOptimalDFTSize( J.rows );
		int n = getOptimalDFTSize( J.cols ); // on the border add zero values
		copyMakeBorder(J, paddedJ, 0, m - J.rows, 0, n - J.cols, BORDER_CONSTANT, Scalar::all(0));
		Mat planesJ[] = {Mat_<float>(paddedJ), Mat::zeros(paddedJ.size(), CV_32F)}; 
		Mat complexJ;
		merge(planesJ, 2, complexJ);         // Add to the expanded another plane with zeros
		dft(complexJ, complexJ , cv::DFT_SCALE|cv::DFT_COMPLEX_OUTPUT);            // this way the result may fit in the source matrix
		split(complexJ, planesJ);                   // planes[0] = Re(DFT(I), planes[1] = Im(DFT(I))
		Mat magJ ,phasJ;
		magnitude(planesJ[0],planesJ[1],magJ);
		phase(planesJ[0],planesJ[1],phasJ);
		int cx = magJ.cols/2;
		int cy = magJ.rows/2;
		Mat q0(magJ, Rect(0, 0, cx, cy));
		Mat q1(magJ, Rect(cx, 0, cx, cy));
		Mat q2(magJ, Rect(0, cy, cx, cy));
		Mat q3(magJ, Rect(cx, cy, cx, cy));
		Mat tmp;
		q0.copyTo(tmp);
		q3.copyTo(q0);
		tmp.copyTo(q3);
		q1.copyTo(tmp);
		q2.copyTo(q1);
		tmp.copyTo(q2);

		//************ END OF FRQ ACQUISITION AND SHIFT *************
		//******** BEGINING OF FILTER DEFINITION *********************************
		Mat H;
		H = Mat::ones(magJ.rows,magJ.cols,CV_8UC1);
		int dims = J.rows*(55/2)/488 ;
		int limity = H.rows;
		int limitx = H.cols;
		int starty = 0;
		int startx = 0;

		int lparam = J.rows*(145 - dims)/488;
		int rparam = J.cols*(145 + dims)/488;

		for(int j=starty;j<limity;j++)
		{uchar *filter = H.ptr<uchar>(j);
		for(int i=startx;i<limitx;i++)
		{

			if((sqrt(pow(float(i-cx),2) + pow(float(j-cy),2) ) <= rparam)&&(sqrt(pow(float(i-cx),2) + pow(float(j-cy),2) ) >= lparam))
				filter[i] = 0;
		}
		}

		H = H * 255;
		H.convertTo(H,magJ.type());
		imwrite("filter.jpg",H);
		//******** END OF FILTER *********************************
		multiply(magJ,H,magJ);
		magJ = magJ/255;
		Mat q5(magJ, Rect(0, 0, cx, cy));
		Mat q6(magJ, Rect(cx, 0, cx, cy));
		Mat q7(magJ, Rect(0, cy, cx, cy));
		Mat q8(magJ, Rect(cx, cy, cx, cy));
		tmp;
		q0.copyTo(tmp);
		q3.copyTo(q0);
		tmp.copyTo(q3);
		q1.copyTo(tmp);
		q2.copyTo(q1);
		tmp.copyTo(q2);
		//***************** END OF MAG OPERATIONS **************
		Mat planesO[2];
		Mat complexO;
		polarToCart(magJ,phasJ,planesO[0],planesO[1]);
		merge(planesO,2,complexO);
		dft(complexO,complexO,cv::DFT_INVERSE);
		split(complexO,planesO);
		planesO[0].convertTo(planesO[0],CV_8UC1);

		Mat2CImage(planesO[0],img);
		UpdateAllViews(0); _pic ++;

	}

	void CMFCSDIDoc::OnEnhancementNotchfilter()
	{
		Mat J;
		CImage2Mat(J,img);
		Mat2CImage(J,imgprv[_pic]);
		if(J.step[1] == 3)
			cvtColor( J, J, CV_BGR2GRAY );
		J.convertTo(J, CV_32F);
		Mat paddedJ;                            //expand input image to optimal size
		int m = getOptimalDFTSize( J.rows );
		int n = getOptimalDFTSize( J.cols ); // on the border add zero values
		copyMakeBorder(J, paddedJ, 0, m - J.rows, 0, n - J.cols, BORDER_CONSTANT, Scalar::all(0));
		Mat planesJ[] = {Mat_<float>(paddedJ), Mat::zeros(paddedJ.size(), CV_32F)}; 
		Mat complexJ;
		merge(planesJ, 2, complexJ);         // Add to the expanded another plane with zeros
		dft(complexJ, complexJ , cv::DFT_SCALE|cv::DFT_COMPLEX_OUTPUT);            // this way the result may fit in the source matrix
		split(complexJ, planesJ);                   // planes[0] = Re(DFT(I), planes[1] = Im(DFT(I))
		Mat magJ ,phasJ;
		magnitude(planesJ[0],planesJ[1],magJ);
		phase(planesJ[0],planesJ[1],phasJ);
		int cx = magJ.cols/2;
		int cy = magJ.rows/2;
		Mat q0(magJ, Rect(0, 0, cx, cy));
		Mat q1(magJ, Rect(cx, 0, cx, cy));
		Mat q2(magJ, Rect(0, cy, cx, cy));
		Mat q3(magJ, Rect(cx, cy, cx, cy));
		Mat tmp;
		q0.copyTo(tmp);
		q3.copyTo(q0);
		tmp.copyTo(q3);
		q1.copyTo(tmp);
		q2.copyTo(q1);
		tmp.copyTo(q2);

		//************ END OF FRQ ACQUISITION AND SHIFT *************
		//******** BEGINING OF FILTER DEFINITION *********************************
		Mat H;
		H = Mat::ones(magJ.rows,magJ.cols,CV_8UC1);

		int limity = H.rows;
		int limitx = H.cols;
		int starty = 0;
		int startx = 0;

		int _width   = 15 ;
		int lparam =  125*J.cols/480 ;
		int rparam = -125*J.rows/480 ;

		for(int j=starty;j<limity;j++)
		{uchar *filter = H.ptr<uchar>(j);
		for(int i=startx;i<limitx;i++)
		{
			if(sqrt(pow(float(lparam+i-cx),2) + pow(float(lparam+j-cy),2) ) < _width)
				filter[i] = 0;
			if(sqrt(pow(float(rparam+i-cx),2) + pow(float(rparam+j-cy),2) ) < _width)
				filter[i] = 0;

			if(sqrt(pow(float(lparam+i-cx),2) + pow(float(rparam+j-cy),2) ) < _width)
				filter[i] = 0;
			if(sqrt(pow(float(rparam+i-cx),2) + pow(float(lparam+j-cy),2) ) < _width)
				filter[i] = 0;

			if(sqrt(pow(float(lparam+i-cx),2) + pow(float(j-cy),2) ) < _width)
				filter[i] = 0;
			if(sqrt(pow(float(rparam+i-cx),2) + pow(float(j-cy),2) ) < _width)
				filter[i] = 0;

			if(sqrt(pow(float(i-cx),2) + pow(float(lparam+j-cy),2) ) < _width)
				filter[i] = 0;
			if(sqrt(pow(float(i-cx),2) + pow(float(rparam+j-cy),2) ) < _width)
				filter[i] = 0;
		}
		}

		H = H * 255;
		H.convertTo(H,magJ.type());
		imwrite("filter.jpg",H);
		//******** END OF FILTER *********************************
		multiply(magJ,H,magJ);
		magJ = magJ/255;
		Mat q5(magJ, Rect(0, 0, cx, cy));
		Mat q6(magJ, Rect(cx, 0, cx, cy));
		Mat q7(magJ, Rect(0, cy, cx, cy));
		Mat q8(magJ, Rect(cx, cy, cx, cy));
		tmp;
		q0.copyTo(tmp);
		q3.copyTo(q0);
		tmp.copyTo(q3);
		q1.copyTo(tmp);
		q2.copyTo(q1);
		tmp.copyTo(q2);
		//***************** END OF MAG OPERATIONS **************
		Mat planesO[2];
		Mat complexO;
		polarToCart(magJ,phasJ,planesO[0],planesO[1]);
		merge(planesO,2,complexO);
		dft(complexO,complexO,cv::DFT_INVERSE);
		split(complexO,planesO);
		planesO[0].convertTo(planesO[0],CV_8UC1);

		Mat2CImage(planesO[0],img);
		UpdateAllViews(0); _pic ++;

	}

	void CMFCSDIDoc::OnEnhancementAtomsphericturb()
	{
		Mat J;
		CImage2Mat(J,img);
		Mat2CImage(J,imgprv[_pic]);
		if(J.step[1] == 3)
			cvtColor( J, J, CV_BGR2GRAY );
		J.convertTo(J, CV_32F);
		Mat paddedJ;                            //expand input image to optimal size
		int m = getOptimalDFTSize( J.rows );
		int n = getOptimalDFTSize( J.cols ); // on the border add zero values
		copyMakeBorder(J, paddedJ, 0, m - J.rows, 0, n - J.cols, BORDER_CONSTANT, Scalar::all(0));
		Mat planesJ[] = {Mat_<float>(paddedJ), Mat::zeros(paddedJ.size(), CV_32F)}; 
		Mat complexJ;
		merge(planesJ, 2, complexJ);         // Add to the expanded another plane with zeros
		dft(complexJ, complexJ , cv::DFT_SCALE|cv::DFT_COMPLEX_OUTPUT);            // this way the result may fit in the source matrix
		split(complexJ, planesJ);                   // planes[0] = Re(DFT(I), planes[1] = Im(DFT(I))
		Mat magJ ,phasJ;
		magnitude(planesJ[0],planesJ[1],magJ);
		phase(planesJ[0],planesJ[1],phasJ);
		int cx = magJ.cols/2;
		int cy = magJ.rows/2;
		Mat q0(magJ, Rect(0, 0, cx, cy));
		Mat q1(magJ, Rect(cx, 0, cx, cy));
		Mat q2(magJ, Rect(0, cy, cx, cy));
		Mat q3(magJ, Rect(cx, cy, cx, cy));
		Mat tmp;
		q0.copyTo(tmp);
		q3.copyTo(q0);
		tmp.copyTo(q3);
		q1.copyTo(tmp);
		q2.copyTo(q1);
		tmp.copyTo(q2);

		//************ END OF FRQ ACQUISITION AND SHIFT *************
		//******** BEGINING OF FILTER DEFINITION *********************************

		Mat H;
		H = Mat::zeros(magJ.rows,magJ.cols,CV_8UC1);

		float K = -1*0.001*fact;
		float _param = 0.8333;
		int limity = H.rows;
		int limitx = H.cols;
		int starty = 0;
		int startx = 0;

		for(int j=starty;j<limity;j++)
		{uchar *filter = H.ptr<uchar>(j);
		for(int i=startx;i<limitx;i++)
		{
			float num = float(pow(float(i-cx),2) + pow(float(j-cy),2));
			num = pow(float(num),float(_param))*K;
			num =  exp(float(num));
			filter[i]  = 255*num ;
		}
		}
		imwrite("filt.jpg",H);
		H.convertTo(H,magJ.type());

		//******** END OF FILTER *********************************
		multiply(magJ,H,magJ);
		magJ = magJ / 255 ;
		Mat q5(magJ, Rect(0, 0, cx, cy));
		Mat q6(magJ, Rect(cx, 0, cx, cy));
		Mat q7(magJ, Rect(0, cy, cx, cy));
		Mat q8(magJ, Rect(cx, cy, cx, cy));
		tmp;
		q0.copyTo(tmp);
		q3.copyTo(q0);
		tmp.copyTo(q3);
		q1.copyTo(tmp);
		q2.copyTo(q1);
		tmp.copyTo(q2);
		//***************** END OF MAG OPERATIONS **************


		Mat planesO[2];
		Mat complexO;
		polarToCart(magJ,phasJ,planesO[0],planesO[1]);
		merge(planesO,2,complexO);
		dft(complexO,complexO,cv::DFT_INVERSE);
		split(complexO,planesO);
		planesO[0].convertTo(planesO[0],CV_8UC1);
		Mat2CImage(planesO[0],img);
		UpdateAllViews(0); _pic ++;
	}

	void CMFCSDIDoc::OnEnhancementMotionblur()
	{	
		Mat J;
		CImage2Mat(J,img);
		Mat2CImage(J,imgprv[_pic]);
		if(J.step[1] == 3)
			cvtColor( J, J, CV_BGR2GRAY );
		J.convertTo(J, CV_32F);
		Mat paddedJ;                            //expand input image to optimal size
		int m = getOptimalDFTSize( J.rows );
		int n = getOptimalDFTSize( J.cols ); // on the border add zero values
		copyMakeBorder(J, paddedJ, 0, m - J.rows, 0, n - J.cols, BORDER_CONSTANT, Scalar::all(0));
		Mat planesJ[] = {Mat_<float>(paddedJ), Mat::zeros(paddedJ.size(), CV_32F)}; 
		Mat complexJ;
		merge(planesJ, 2, complexJ);         // Add to the expanded another plane with zeros
		dft(complexJ, complexJ , cv::DFT_SCALE|cv::DFT_COMPLEX_OUTPUT);            // this way the result may fit in the source matrix
		split(complexJ, planesJ);                   // planes[0] = Re(DFT(I), planes[1] = Im(DFT(I))
		Mat magJ ,phasJ;
		magnitude(planesJ[0],planesJ[1],magJ);
		phase(planesJ[0],planesJ[1],phasJ);
		int cx = magJ.cols/2;
		int cy = magJ.rows/2;


		Mat q0(magJ, Rect(0, 0, cx, cy));
		Mat q1(magJ, Rect(cx, 0, cx, cy));
		Mat q2(magJ, Rect(0, cy, cx, cy));
		Mat q3(magJ, Rect(cx, cy, cx, cy));
		Mat tmp;
		q0.copyTo(tmp);
		q3.copyTo(q0);
		tmp.copyTo(q3);
		q1.copyTo(tmp);
		q2.copyTo(q1);
		tmp.copyTo(q2);

		//************ END OF FRQ ACQUISITION AND SHIFT *************
		//******** BEGINING OF FILTER DEFINITION *********************************
		Mat H,G;
		H = Mat::zeros(magJ.rows,magJ.cols,CV_32FC1);
		G = Mat::zeros(magJ.rows,magJ.cols,CV_32FC1);

		int limity = H.rows;
		int limitx = H.cols;
		int starty = 0;
		int startx = 0;

		float pi = CV_PI;
		float _a = 0.1;
		float _b = 0.1;
		for(int j=starty;j<limity;j++)
		{
			float *filterR = H.ptr<float>(j);
			float *filterI = G.ptr<float>(j);
			for(int i=startx;i<limitx;i++)
			{
				float num = float(pi*(float(_a*i - cx) + float(_b*j - cy)) );
				filterI[i]  = float(pi*(float(_a*i) + float(_b*j)));
				num = float(sin(num)/num) ;
				filterR[i] = num;
			}
		}
		G = G*(-1);
		normalize(H,H,1,0,CV_MINMAX);
		H.convertTo(H,magJ.type());
		G.convertTo(G,magJ.type());
		//******** END OF FILTER *********************************

		multiply(magJ,H,magJ);
		phasJ += G;
		q0.copyTo(tmp);
		q3.copyTo(q0);
		tmp.copyTo(q3);
		q1.copyTo(tmp);
		q2.copyTo(q1);
		tmp.copyTo(q2);

		//***************** END OF MAG OPERATIONS **************

		Mat planesO[2];
		Mat complexO;
		polarToCart(magJ,phasJ,planesO[0],planesO[1]);
		merge(planesO,2,complexO);
		dft(complexO,complexO,cv::DFT_INVERSE);
		split(complexO,planesO);
		planesO[0].convertTo(planesO[0],CV_8UC1);
		Mat2CImage(planesO[0],img);
		UpdateAllViews(0); _pic ++;

	}

	void CMFCSDIDoc::OnColorfullFalsecolor()
	{
		Mat J;
		CImage2Mat(J,img);
		Mat2CImage(J,imgprv[_pic]);
		if(J.step[1] == 3)
			cvtColor( J, J, CV_BGR2GRAY );
		Mat result = Mat::zeros(J.rows,J.cols,CV_8UC3);
		int limitx = J.cols;

		for(int j=0 ; j< J.rows;j++)
		{	uchar *data = J.ptr<uchar>(j);
		uchar *datares = result.ptr<uchar>(j);
		for(int i =0 ; i< limitx ;i++)
		{
			int dec = data[i]/10;

			if(dec<=10)
				datares[3*i]   = data[i];
			else if(dec<=17)
				datares[3*i+1] = data[i];
			else 
				datares[3*i+2] = data[i];
		}
		}

		Mat2CImage(result,img);
		UpdateAllViews(0); _pic ++;

	}

	void CMFCSDIDoc::OnColorfullBoostingcont()
	{
		Mat J;
		CImage2Mat(J,img);
		Mat2CImage(J,imgprv[_pic]);
		Mat Jh,_temp,_tempres;
		cvtColor(J,Jh,CV_BGR2HSV);
		_temp = Mat::zeros(Jh.rows,Jh.cols,CV_8UC1);
		_tempres = Mat::zeros(Jh.rows,Jh.cols,CV_8UC1);

		for(int j=0 ; j<Jh.rows;j++)
		{uchar *data = Jh.ptr<uchar>(j);
		uchar *datat = _temp.ptr<uchar>(j);
		for(int i=0; i<Jh.cols;i++)
		{	
			datat[i] = data[3*i+2];
		}
		}

		int nl = _temp.rows;
		int nc = (_temp.cols)*(_temp.channels()) ;
		_tempres.create(nl,_temp.cols,_temp.type());
		float _fct = 20/abs(fact) ;
		for(int j = 0 ; j < (nl); j ++)
		{
			uchar* _datares = _tempres.ptr<uchar>(j);
			uchar* _data = _temp.ptr<uchar>(j);
			for ( int i=0 ; i < nc ;i++)
			{
				float tmp = _data[i];
				if(fact >= 1)
					tmp  =  float(pow((tmp/255),float(_fct)));
				if(fact <= -1)
					tmp  =  float(pow((tmp/255),float(1/_fct)));
				_datares[i]  = 255*tmp;
			}
		}


		for(int j=0 ; j<Jh.rows;j++)
		{uchar *data = Jh.ptr<uchar>(j);
		uchar *datat = _tempres.ptr<uchar>(j);
		for(int i=0; i<Jh.cols;i++)
		{	
			data[3*i+2] = datat[i];
		}
		}


		cvtColor(Jh,J,CV_HSV2BGR);
		Mat2CImage(J,img);
		UpdateAllViews(0); _pic ++;

	}

	void CMFCSDIDoc::OnColorfullNegative()
	{
		Mat J;
		CImage2Mat(J,img);
		Mat2CImage(J,imgprv[_pic]);
		Mat Jh;
		cvtColor(J,Jh,CV_BGR2HSV);

		for(int j=0 ; j<Jh.rows;j++)
		{uchar *data = Jh.ptr<uchar>(j);
		for(int i=0; i<Jh.cols;i++)
		{	
			data[3*i+2] = 255 - data[3*i+2];
		}
		}
		cvtColor(Jh,J,CV_HSV2BGR);
		Mat2CImage(J,img);
		UpdateAllViews(0); _pic ++;


	}

	void CMFCSDIDoc::OnColorfullExtraction()
	{
		Mat J;
		CImage2Mat(J,img);
		Mat2CImage(J,imgprv[_pic]);

		int ar = 175;
		int wr =  pow(float(65),2);
		int ag = 40;
		int ab = 49; 

		for(int j=0 ; j<J.rows;j++)
		{uchar *data = J.ptr<uchar>(j);
		for(int i=0; i<J.cols;i++)
		{	
			if( pow(float(data[3*i+2]-ar),2) + pow(float(data[3*i+1]-ag),2) + pow(float(data[3*i]-ab),2) > wr )
			{	data[3*i]   = 127;
			data[3*i+1] = 127;
			data[3*i+2] = 127;
			}
		}
		}

		Mat2CImage(J,img);
		UpdateAllViews(0); _pic ++;



	}

	void CMFCSDIDoc::OnColorfullEqualization()
	{
		Mat J;
		CImage2Mat(J,img);
		Mat2CImage(J,imgprv[_pic]);
		
		Mat ycrcb;
		cvtColor(J,ycrcb,CV_BGR2YCrCb);
        vector<Mat> channels;
        split(ycrcb,channels);
        equalizeHist(channels[0], channels[0]);
        merge(channels,ycrcb);
        cvtColor(ycrcb,J,CV_YCrCb2BGR);
	
		Mat2CImage(J,img);
		UpdateAllViews(0); _pic ++;
	}

	void CMFCSDIDoc::OnColorfullHsi()
	{
		Mat J;
		CImage2Mat(J,img);
		Mat2CImage(J,imgprv[_pic]);

		int kernel_size = 5 ;
		Mat kernel = Mat::ones( kernel_size, kernel_size, CV_32F )/ (float)(kernel_size*kernel_size);
		filter2D(J,J,J.depth(),kernel);


		Mat Jh;
		cvtColor(J,Jh,CV_BGR2HSV);
		Mat _Intens = Mat::zeros(Jh.rows,Jh.cols,CV_8UC1);
		for(int j=0 ; j<Jh.rows;j++)
		{uchar *data = Jh.ptr<uchar>(j);
		uchar *temp = _Intens.ptr<uchar>(j);
		for(int i=0; i<Jh.cols;i++)
			temp[i] = data[3*i+2];
		}
		filter2D(_Intens,_Intens,_Intens.depth(),kernel);
		for(int j=0 ; j<Jh.rows;j++)
		{uchar *data = Jh.ptr<uchar>(j);
		uchar *temp = _Intens.ptr<uchar>(j);
		for(int i=0; i<Jh.cols;i++)
			data[3*i+2] = temp[i];
		}

		cvtColor(Jh,Jh,CV_HSV2BGR);
		J = J - Jh;
		normalize(J,J,255,0,CV_MINMAX);
		Mat2CImage(J,img);
		UpdateAllViews(0); _pic ++;

	}

	void CMFCSDIDoc::OnColorfullEdgedetection()
	{
		Mat J;
		CImage2Mat(J,img);
		Mat2CImage(J,imgprv[_pic]);

		Mat RES1 = Mat::zeros(J.rows,J.cols,CV_32FC1);
		Mat RES2 = Mat::zeros(J.rows,J.cols,CV_32FC1);

		int limity = J.rows - 1;
		int nc = J.step[1]  ;
		int limitx = J.step[0] - nc;
		for(int j=1 ; j<limity;j++)
		{
			uchar *crt = J.ptr<uchar>(j);
			uchar *nxt = J.ptr<uchar>(j+1);
			uchar *prv = J.ptr<uchar>(j-1);
			float *data1 = RES1.ptr<float>(j);
			for(int i=nc; i<limitx;)
			{
				float UB = (prv[i+nc] + 2*crt[i+nc] + nxt[i+nc] - nxt[i-nc] - 2*crt[i-nc] - prv[i-nc]);
				float VB = (2*nxt[i] + nxt[i+nc] + nxt[i-nc] - prv[i-nc] - 2*prv[i] - prv[i+nc]);
				i++;
				float UG = (prv[i+nc] + 2*crt[i+nc] + nxt[i+nc] - nxt[i-nc] - 2*crt[i-nc] - prv[i-nc]);
				float VG = (2*nxt[i] + nxt[i+nc] + nxt[i-nc] - prv[i-nc] - 2*prv[i] - prv[i+nc]);
				i++;
				float UR = (prv[i+nc] + 2*crt[i+nc] + nxt[i+nc] - nxt[i-nc] - 2*crt[i-nc] - prv[i-nc]);
				float VR = (2*nxt[i] + nxt[i+nc] + nxt[i-nc] - prv[i-nc] - 2*prv[i] - prv[i+nc]);
				i++;

				float gxx = pow(float(UR),2) + pow(float(UG),2) + pow(float(UB),2) ;
				float gyy = pow(float(VR),2) + pow(float(VG),2) + pow(float(VB),2) ;
				float gxy = UR*VR + VG*UG + VB*UB ;

				float PI = 3.141592;
				float teta = float(0.5*atan(float(2*gxy/abs(gxx-gyy))));
				while(teta<0)
					teta = teta+PI;
				while(teta>PI)
					teta = teta-PI;
				data1[i/3] = float(sqrt(0.5*float((gxx+gyy) + float(abs(gxx-gyy)*cos(2*teta)) + float(2*gxy*sin(2*teta)))));	
			}
		}


		Mat tmp;
		Mat kern = (Mat_<char>(3,3) << -1, -2, -1,
			0, 0, 0,
			1, 2, 1);
		filter2D(J,RES2,J.depth(),kern);
		kern = (Mat_<char>(3,3) << -1, 0, 1,
			-2, 0, 2,
			-1, 0, 1);
		filter2D(J,J,J.depth(),kern);
		RES2 += J;

		RES1.convertTo(RES1,CV_8UC1);
		cvtColor(RES2,RES2,CV_BGR2GRAY);
		RES2.convertTo(RES2,CV_8UC1);

		//RES1 = RES1-RES2;
		Mat2CImage(RES1,img);
		UpdateAllViews(0); _pic ++;

	}

	void CMFCSDIDoc::OnEnhancementGeometrictrans()
	{
		Mat J;
		CImage2Mat(J,img);
		Mat2CImage(J,imgprv[_pic]);


		Point2f srcTri[4];
		Point2f dstTri[4];

		int _R = J.rows;
		int _C = J.cols;

		srcTri[0] = Point2f(0,0);
		srcTri[1] = Point2f(0,_R);
		srcTri[2] = Point2f(_C,0);
		srcTri[3] = Point2f(_C,_R);

		dstTri[0] = Point2f(_C*0.25,_R*0.5);
		dstTri[1] = Point2f(_C*(0.9),_R*(0.63));
		dstTri[2] = Point2f(_C*(0.7),_R*(0.375));
		dstTri[3] = Point2f(_C*(1),_R*(.84));

		Mat wrap_mat = getAffineTransform(srcTri,dstTri);
		Size M = (J.size());
		warpAffine(J,J,wrap_mat,M);
		Mat2CImage(J,img);
		UpdateAllViews(0); _pic ++;

	}

	void CMFCSDIDoc::OnWaveletDebuachi()
	{
		Mat J;
		CImage2Mat(J,img);
		Mat2CImage(J,imgprv[_pic]);

		//Mat H0 = (Mat_<float>(1,8)<< 0, 0,0,0,0,0,0,1 );
		Mat H0 = (Mat_<float>(1,8)<< (-0.00751),  (0.02334),(0.02189),(-0.13279), (-0.019868) ,(0.44792),(0.507536) ,(0.16356) );
		Mat H1 = (Mat_<float>(1,8)<< (-0.00751),  (-0.02334),(0.02189),(0.13279), (-0.019868) ,(-0.44792),(0.507536) ,(-0.16356) );
		Mat G0 = (Mat_<float>(1,8)<< (-0.00751),  (0.02334),(0.02189),(-0.13279), (-0.019868) ,(0.44792),(0.507536) ,(0.16356) );
		Mat G1 = (Mat_<float>(1,8)<< (-0.00751),  (-0.02334),(0.02189),(0.13279), (-0.019868) ,(-0.44792),(0.507536) ,(-0.16356) );

		Mat JL;JL = Mat::zeros(J.size(),J.type());
		Mat JH;JH = Mat::zeros(J.size(),J.type());

		Mat JLD;JLD = Mat::zeros((J.rows/2),(J.cols),J.type());
		Mat JLDL;JLDL = Mat::zeros((J.rows/2),(J.cols),J.type());
		Mat JLDH;JLDH = Mat::zeros((J.rows/2),(J.cols),J.type());
		Mat JLDLD;JLDLD = Mat::zeros((J.rows/2),(J.cols/2),J.type());
		Mat JLDHD;JLDHD = Mat::zeros((J.rows/2),(J.cols/2),J.type());

		Mat JHD;JHD = Mat::zeros((J.rows/2),(J.cols),J.type());
		Mat JHDL;JHDL = Mat::zeros((J.rows/2),(J.cols),J.type());
		Mat JHDH;JHDH = Mat::zeros((J.rows/2),(J.cols),J.type());
		Mat JHDLD;JHDLD = Mat::zeros((J.rows/2),(J.cols/2),J.type());
		Mat JHDHD;JHDHD = Mat::zeros((J.rows/2),(J.cols/2),J.type());


		for(int j=0 ; j<J.rows;j++)
		{
			//************* LOW ROW ***************
			Mat sub(J,Rect(0,j,J.cols,1));
			Mat subr(JL,Rect(0,j,J.cols,1));
			filter2D(sub,subr,sub.depth(),H0);
			Mat subr2(JLD,Rect(0,(j/2),J.cols,1));
			subr.copyTo(subr2);

			//************* HIGH ROW ***************
			Mat subh(JH,Rect(0,j,J.cols,1));
			filter2D(sub,subh,sub.depth(),H1);
			Mat subh2(JHD,Rect(0,(j/2),J.cols,1));
			subh.copyTo(subh2);

		}
		//************ LOW ROW FIRST STEP*************
		for(int i=0 ; i<JLD.cols;i++)
		{
			//************ COLUMN LOW  ***********
			Mat sub1(JLD,Rect(i,0,1,JLD.rows));
			Mat subl1(JLDL,Rect(i,0,1,JLD.rows));
			filter2D(sub1,subl1,sub1.depth(),H0);
			Mat subll1(JLDLD,Rect((i/2),0,1,JLDL.rows));
			subl1.copyTo(subll1);

			Mat subh1(JLDH,Rect(i,0,1,JLD.rows));
			filter2D(sub1,subh1,sub1.depth(),H1);
			Mat subhh1(JLDHD,Rect((i/2),0,1,JLDL.rows));
			subh1.copyTo(subhh1);

			//************  COLUMN HIGH  ***********
			Mat sub2(JHD,Rect(i,0,1,JLD.rows));
			Mat subl2(JHDL,Rect(i,0,1,JLD.rows));
			filter2D(sub2,subl2,sub2.depth(),H0);
			Mat subll2(JHDLD,Rect((i/2),0,1,JLDL.rows));
			subl2.copyTo(subll2);

			Mat subh2(JHDH,Rect(i,0,1,JLD.rows));
			filter2D(sub2,subh2,sub2.depth(),H1);
			Mat subhh2(JHDHD,Rect((i/2),0,1,JLDL.rows));
			subh2.copyTo(subhh2);
		}
		// ********** END OF 1 TIME DOING OP. ********

		Mat2CImage(JLDLD,img);
		imshow("L0 -> H0",JLDHD);
		imshow("H0 -> L0",JHDLD);
		imshow("H0 -> H0",JHDHD);
		UpdateAllViews(0); _pic ++;
	}

	void CMFCSDIDoc::OnMorphologDilation()
	{
		Mat J;
		CImage2Mat(J,img);
		Mat2CImage(J,imgprv[_pic]);

		if(J.step[1]==3)
		{	
			cvtColor( J, J, CV_BGR2GRAY );
			J.convertTo(J,CV_8UC1);
		}
		Mat kern = Mat::ones(1,100,CV_8UC1);
		Mat Jh;
		Jh = ~J;
		dilate(J,Jh,kern);
		J = (~J)&Jh;
		Mat2CImage(J,img);
		UpdateAllViews(0); _pic ++;
	}

	void CMFCSDIDoc::OnMorphologErotion()
	{
		Mat J;
		CImage2Mat(J,img);
		Mat2CImage(J,imgprv[_pic]);
		if(J.step[1]==3)
		{	
			cvtColor( J, J, CV_BGR2GRAY );
			J.convertTo(J,CV_8UC1);
		}
		//J = ~J;
		Mat kern = Mat::ones(10,10,CV_8UC1);
		for(int i=0 ; i<1 ;i++)	
			erode(J,J,kern);

		Mat2CImage(J,img);
		UpdateAllViews(0); _pic ++;
	}

	void CMFCSDIDoc::OnMorphologOpening()
	{
		Mat J;
		CImage2Mat(J,img);
		Mat2CImage(J,imgprv[_pic]);
		if(J.step[1]==3)
		{	
			cvtColor( J, J, CV_BGR2GRAY );
			J.convertTo(J,CV_8UC1);
		}
		Mat kern = Mat::ones(3,3,CV_8UC1);
		for(int i=0 ; i<1 ;i++)	
			erode(J,J,kern);
		for(int i=0 ; i<1 ;i++)	
			dilate(J,J,kern);

		Mat2CImage(J,img);
		UpdateAllViews(0); _pic ++;

	}

	void CMFCSDIDoc::OnMorphologClosing()
	{
		Mat J;
		CImage2Mat(J,img);
		Mat2CImage(J,imgprv[_pic]);
		if(J.step[1]==3)
		{	
			cvtColor( J, J, CV_BGR2GRAY );
			J.convertTo(J,CV_8UC1);
		}
		Mat kern = Mat::ones(10,10,CV_8UC1);
		for(int i=0 ; i<1 ;i++)	
			dilate(J,J,kern);
		for(int i=0 ; i<1 ;i++)	
			erode(J,J,kern);

		Mat2CImage(J,img);
		UpdateAllViews(0); _pic ++;

	}

	void CMFCSDIDoc::OnMorpholog32850()
	{
		Mat J;
		CImage2Mat(J,img);
		Mat2CImage(J,imgprv[_pic]);
		if(J.step[1]==3)
		{	
			cvtColor( J, J, CV_BGR2GRAY );
			J.convertTo(J,CV_8UC1);
		}
		Mat kern = Mat::ones(3,3,CV_8UC1);
		for(int i=0 ; i<1 ;i++)	
			erode(J,J,kern);
		for(int i=0 ; i<1 ;i++)	
			dilate(J,J,kern);
		for(int i=0 ; i<1 ;i++)	
			dilate(J,J,kern);
		for(int i=0 ; i<1 ;i++)	
			erode(J,J,kern);

		Mat2CImage(J,img);
		UpdateAllViews(0); _pic ++;

	}

	void CMFCSDIDoc::OnMorphologHitormiss()
	{

		Mat J;
		CImage2Mat(J,img);
		Mat2CImage(J,imgprv[_pic]);
		if(J.step[1]==3)
		{	
			cvtColor( J, J, CV_BGR2GRAY );
			J.convertTo(J,CV_8UC1);
		}
		int width = 9;
		Mat kern = Mat::ones(width,width,CV_8UC1);
		Mat wkern = Mat::ones(3*width,3*width,CV_8UC1);
		wkern(Rect(width,width,width,width)) =kern(Rect(0,0,width,width)) - wkern(Rect(width,width,width,width));


		Mat temp,tempp;
		for(int i=0 ; i<1 ;i++)	
			erode(J,temp,kern);
		J = ~J;
		for(int i=0 ; i<1 ;i++)	
			erode(J,tempp,wkern);
		J = temp&tempp;

		for(int i=0 ; i<1 ;i++)	
			dilate(J,J,kern);

		Mat2CImage(J,img);
		UpdateAllViews(0); _pic ++;


	}

	void CMFCSDIDoc::OnMorphologBoundaryextrac()
	{

		Mat J;
		CImage2Mat(J,img);
		Mat2CImage(J,imgprv[_pic]);
		if(J.step[1]==3)
		{	
			cvtColor( J, J, CV_BGR2GRAY );
			J.convertTo(J,CV_8UC1);
		}
		Mat kern = Mat::ones(3,3,CV_8UC1);
		Mat temp;
		for(int i=0 ; i<1 ;i++)	
			erode(J,temp,kern);
		J = J - temp;
		Mat2CImage(J,img);
		UpdateAllViews(0); _pic ++;


	}

	void CMFCSDIDoc::OnMorphologRegionfilling()
	{
		Mat J;
		CImage2Mat(J,img);
		Mat2CImage(J,imgprv[_pic]);
		if(J.step[1]==3)
		{	
			cvtColor( J, J, CV_BGR2GRAY );
			J.convertTo(J,CV_8UC1);
		}
		Mat kern = (Mat_<unsigned char>(3,3) << 0,1,0,1,1,1,0,1,0);
		Mat wkern = Mat::ones(3,3,CV_8UC1);
		Mat temp = Mat::zeros(J.rows,J.cols,J.type());
		Mat JP = ~J;
		temp(Rect(10,10,3,3)) = wkern*255;
		for(int i=0 ; i < 1000 ;i++)
		{
			dilate(temp,temp,kern);
			temp = temp&JP;
		}
		temp = ~temp;
		Mat2CImage(temp,img);
		UpdateAllViews(0); _pic ++;

	}

	void CMFCSDIDoc::OnSegmentationLinking()
	{
		Mat J;
		CImage2Mat(J,img);
		Mat2CImage(J,imgprv[_pic]);
		if(J.step[1]==3)
		{	
			cvtColor( J, J, CV_BGR2GRAY );
			J.convertTo(J,CV_8UC1);
		}
		Mat res = Mat::zeros(J.size(),CV_8UC1);
		int limity = J.rows - 1;
		int limitx = J.cols - 1;

		float pi = CV_PI;
		float tm = 75;
		float tp = float(pi/2);
		float eps = float(pi);

		float max=0,min=0;

		for(int j=1 ; j<limity;j++)
		{
			uchar *crt = J.ptr<uchar>(j);
			uchar *nxt = J.ptr<uchar>(j+1);
			uchar *prv = J.ptr<uchar>(j-1);
			uchar *data = res.ptr<uchar>(j);
			for(int i=1; i<limitx;i++)
			{
				float gy = float(prv[i+1] + 2*crt[i+1] + nxt[i+1] - nxt[i-1] - 2*crt[i-1] - prv[i-1]);
				float gx = float(2*nxt[i] + nxt[i+1] + nxt[i-1] - prv[i-1] - 2*prv[i] - prv[i+1]);
				float mag = sqrt(pow(float(gx),2) + pow(float(gy),2)) ;
				float phas = atan(float(gy/gx));
				if(mag>tm)
					if(abs(abs(phas)-tp)<eps)
						data[i] = 255;
			}
		}

		Mat restp = Mat::zeros(res.size(),res.type());
		for(int j=1; j<limity ; j++)
		{
			uchar *data = restp.ptr<uchar>(j);
			uchar *prv = res.ptr<uchar>(j-1);
			uchar *nxt = res.ptr<uchar>(j+1);
			uchar *cnt = res.ptr<uchar>(j+1);

			for(int i=0 ;i<limitx;i++)
			{
				if(cnt[i]!=255)
				{
					if((prv[i]==255)||(prv[i-1]==255)||(prv[i+1]==255)||(nxt[i]==255)||(nxt[i-1]==255)||(nxt[i+1]==255))
						data[i] = 255;
					else
						data[i] = cnt[i];
				}
			}
		}


		Mat2CImage(res,img);
		UpdateAllViews(0); _pic ++;
	}

	void CMFCSDIDoc::OnSegmentationLinedetec()
	{
		Mat src;
		CImage2Mat(src,img);
		Mat2CImage(src,imgprv[_pic]);
		if(src.step[1]==3)
		{	
			cvtColor( src, src, CV_BGR2GRAY );
			src.convertTo(src,CV_8UC1);
		}
		Mat dst , cdst;
		Canny(src, dst, 50, 200, 3);
		cvtColor(dst, cdst, CV_GRAY2BGR);
#if 0
		vector<Vec2f> lines;
		HoughLines(dst, lines, 1, CV_PI/180, 100, 0, 0 );
		for( size_t i = 0; i < lines.size(); i++ )
		{
			float rho = lines[i][0], theta = lines[i][1];
			Point pt1, pt2;
			double a = cos(theta), b = sin(theta);
			double x0 = a*rho, y0 = b*rho;
			pt1.x = cvRound(x0 + 1000*(-b));
			pt1.y = cvRound(y0 + 1000*(a));
			pt2.x = cvRound(x0 - 1000*(-b));
			pt2.y = cvRound(y0 - 1000*(a));
			line( cdst, pt1, pt2, Scalar(0,0,255), 3, CV_AA);
		}
#else
		vector<Vec4i> lines;
		HoughLinesP(dst, lines, 1, CV_PI/180, 50, 5*fact, 10 );
		for( size_t i = 0; i < lines.size(); i++ )
		{
			Vec4i l = lines[i];
			line( cdst, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0,0,255), 3, CV_AA);
		}
#endif

		Mat2CImage(cdst,img);
		UpdateAllViews(0); _pic ++;
	}

	void CMFCSDIDoc::OnSegmentationCircledetec()
	{
		Mat src;
		CImage2Mat(src,img);
		Mat2CImage(src,imgprv[_pic]);
		if(src.step[1]==3)
			cvtColor( src, src, CV_BGR2GRAY );
		GaussianBlur( src, src, Size(9, 9), 2, 2 );
		int minrd = 1;
		int maxrd = 300;

		Mat dsrc;
		cvtColor( src, dsrc, CV_GRAY2BGR);
		vector<Vec3f> circles;
		HoughCircles(src, circles, CV_HOUGH_GRADIENT, 1, 10,100, 30, minrd,maxrd );
		for( size_t i = 0; i < circles.size(); i++ )
		{
			Vec3i c = circles[i];
			circle( dsrc, Point(c[0], c[1]), c[2], Scalar(0,0,255), 3, CV_AA);
			circle( dsrc, Point(c[0], c[1]), 2, Scalar(0,0,255), 3, CV_AA);
		}

		Mat2CImage(dsrc,img);
		UpdateAllViews(0); _pic ++;
	}

	void CMFCSDIDoc::OnMorphologConvex()
	{
		Mat J;
		CImage2Mat(J,img);
		Mat2CImage(J,imgprv[_pic]);
		if(J.step[1]==3)
		{	
			cvtColor( J, J, CV_BGR2GRAY );
			J.convertTo(J,CV_8UC1);
		}
		int limity = J.rows - 1;
		int limitx = J.cols - 1;

		Mat res1 = J;
		Mat res2 = J;
		Mat res3 = J;
		Mat res4 = J;

		for(int j=1 ; j<limity;j++)
		{
			uchar *crt = res1.ptr<uchar>(j);
			uchar *nxt = res1.ptr<uchar>(j+1);
			uchar *prv = res1.ptr<uchar>(j-1);
			uchar *data1 = res1.ptr<uchar>(j);
			for(int i=1; i<limitx;i++)
				for(int k=0; k<10;k++)
					//  B1
					if((crt[i]<10)&&(crt[i-1]>250)&&(prv[i-1]>250)&&(nxt[i-1]>250))
						data1[i] = 254; 
		}

		for(int j=1 ; j<limity;j++)
		{
			uchar *crt = res2.ptr<uchar>(j);
			uchar *nxt = res2.ptr<uchar>(j+1);
			uchar *prv = res2.ptr<uchar>(j-1);
			uchar *data2 = res2.ptr<uchar>(j);
			for(int i=1; i<limitx;i++)
				for(int k=0; k<10;k++)
					//  B2
					if((crt[i]<10)&&(prv[i-1]>250)&&(prv[i+1]>250)&&(prv[i]>250))
						data2[i] = 254;
		}
		for(int j=1 ; j<limity;j++)
		{
			uchar *crt = res3.ptr<uchar>(j);
			uchar *nxt = res3.ptr<uchar>(j+1);
			uchar *prv = res3.ptr<uchar>(j-1);
			uchar *data3 = res3.ptr<uchar>(j);
			for(int i=1; i<limitx;i++)
				for(int k=0; k<10;k++)
					//  B3
					if((crt[i]<10)&&(crt[i+1]>250)&&(prv[i+1]>250)&&(nxt[i+1]>250))
						data3[i] = 254;
		}
		for(int j=1 ; j<limity;j++)
		{
			uchar *crt = res4.ptr<uchar>(j);
			uchar *nxt = res4.ptr<uchar>(j+1);
			uchar *prv = res4.ptr<uchar>(j-1);
			uchar *data4 = res4.ptr<uchar>(j);
			for(int i=1; i<limitx;i++)
				for(int k=0; k<10;k++)
					//  B4
					if((crt[i]<10)&&(nxt[i-1]>250)&&(nxt[i+1]>250)&&(nxt[i]>250))
						data4[i] = 254;
		}

		int thresh = 100;
		int max_thresh = 255;
		RNG rng(12345);
		blur( J, J, Size(3,3) );
		Mat threshold_output;
		vector<vector<Point> > contours;
		vector<Vec4i> hierarchy;
		threshold( J, threshold_output, thresh, max_thresh, THRESH_BINARY );
		findContours( threshold_output, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );
		vector<vector<Point> >hull( contours.size() );
		for( int i = 0; i < contours.size(); i++ )
		{ convexHull( Mat(contours[i]), hull[i], false ); }
		Mat drawing = Mat::zeros( threshold_output.size(), CV_8UC3 );
		for( int i = 0; i< contours.size(); i++ )
		{
			Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
			drawContours( drawing, contours, i, color, 1, 8, vector<Vec4i>(), 0, Point() );
			drawContours( drawing, hull, i, color, 1, 8, vector<Vec4i>(), 0, Point() );
		}

		Mat2CImage(drawing,img);
		UpdateAllViews(0); _pic ++;
	}

	void CMFCSDIDoc::OnEnhancementInversefilt()
	{
		Mat J;
		CImage2Mat(J,img);
		Mat2CImage(J,imgprv[_pic]);
		if(J.step[1] == 3)
			cvtColor( J, J, CV_BGR2GRAY );
		J.convertTo(J, CV_32F);
		Mat paddedJ;                            //expand input image to optimal size
		int m = getOptimalDFTSize( J.rows );
		int n = getOptimalDFTSize( J.cols ); // on the border add zero values
		copyMakeBorder(J, paddedJ, 0, m - J.rows, 0, n - J.cols, BORDER_CONSTANT, Scalar::all(0));
		Mat planesJ[] = {Mat_<float>(paddedJ), Mat::zeros(paddedJ.size(), CV_32F)}; 
		Mat complexJ;
		merge(planesJ, 2, complexJ);         // Add to the expanded another plane with zeros
		dft(complexJ, complexJ , cv::DFT_SCALE|cv::DFT_COMPLEX_OUTPUT);            // this way the result may fit in the source matrix
		split(complexJ, planesJ);                   // planes[0] = Re(DFT(I), planes[1] = Im(DFT(I))
		Mat magJ ,phasJ;
		magnitude(planesJ[0],planesJ[1],magJ);
		phase(planesJ[0],planesJ[1],phasJ);
		int cx = magJ.cols/2;
		int cy = magJ.rows/2;
		Mat q0(magJ, Rect(0, 0, cx, cy));
		Mat q1(magJ, Rect(cx, 0, cx, cy));
		Mat q2(magJ, Rect(0, cy, cx, cy));
		Mat q3(magJ, Rect(cx, cy, cx, cy));
		Mat tmp;
		q0.copyTo(tmp);
		q3.copyTo(q0);
		tmp.copyTo(q3);
		q1.copyTo(tmp);
		q2.copyTo(q1);
		tmp.copyTo(q2);

		//************ END OF FRQ ACQUISITION AND SHIFT *************
		//******** BEGINING OF FILTER DEFINITION *********************************


		Mat H;
		H = Mat::zeros(magJ.rows,magJ.cols,CV_8UC1);
		int dims = 10*fact;
		int _n = 1;
		int limity = H.rows;//(cy+dims);
		int limitx = H.cols;//(cx+dims);
		int starty = 0;//(cy-dims);
		int startx = 0;// (cx-dims);
		float k = -0.0025;
		float po = 0.833;
		for(int j=starty;j<limity;j++)
		{uchar *filter = H.ptr<uchar>(j);
		for(int i=startx;i<limitx;i++)
		{
			float num = float(pow(float(i-cx),2) + pow(float(j-cy),2));
			num =  exp(pow(float(num),po));
			num = num*k;
			filter[i] = 255*num;
		}
		}
		H.convertTo(H,magJ.type());
		//******** END OF FILTER *********************************
		multiply(magJ,H,magJ);
		magJ = magJ/255;
		Mat q5(magJ, Rect(0, 0, cx, cy));
		Mat q6(magJ, Rect(cx, 0, cx, cy));
		Mat q7(magJ, Rect(0, cy, cx, cy));
		Mat q8(magJ, Rect(cx, cy, cx, cy));
		tmp;
		q0.copyTo(tmp);
		q3.copyTo(q0);
		tmp.copyTo(q3);
		q1.copyTo(tmp);
		q2.copyTo(q1);
		tmp.copyTo(q2);
		//***************** END OF MAG OPERATIONS **************
		Mat planesO[2];
		Mat complexO;
		polarToCart(magJ,phasJ,planesO[0],planesO[1]);
		merge(planesO,2,complexO);
		dft(complexO,complexO,cv::DFT_INVERSE);
		split(complexO,planesO);
		planesO[0].convertTo(planesO[0],CV_8UC1);
		Mat2CImage(planesO[0],img);
		UpdateAllViews(0); _pic ++;

	}

	void CMFCSDIDoc::OnEnhancementMotionblurspat()
	{
		Mat _temp,_tempres;
		CImage2Mat(_temp,img);
		Mat2CImage(_temp,imgprv[_pic]);
		/*int nc = _temp.channels();
		int kernel_size = 3*fact;
		int border = kernel_size/2;

		Mat kern = (Mat_<float>(5,5)<< 1,1,0,0,0,
			1,1,1,0,0,
			0,1,1,1,0,
			0,0,1,1,1,
			0,0,0,1,1);
		kern = kern/12;
		if(fact > 1){
			kern = (Mat_<float>(7,7)<<     1,1,0,0,0,0,0,
				1,1,1,0,0,0,0,
				0,1,1,1,0,0,0,
				0,0,1,1,1,0,0,
				0,0,0,1,1,1,0,
				0,0,0,0,1,1,1,
				0,0,0,0,0,1,1);
			kern = kern/18;
		}
		_tempres.create(_temp.rows,_temp.cols,_temp.type());
		filter2D(_temp,_tempres,_temp.depth(),kern);
		*/
		Mat tempres ;
		Mat _OUT;
		_OUT = _temp;

		for( int i=0; i< 10;i++)
		{

			tempres = _temp(Rect(i,i,(_temp.cols - i),((_temp.rows - i))));
			copyMakeBorder(tempres,tempres,0,i,0,i,BORDER_CONSTANT, Scalar::all(0));
			_OUT = _OUT + tempres;
			_OUT = _OUT/2;
		}
		
		Mat2CImage(_OUT,img);
		UpdateAllViews(0); _pic ++;
	}

	void CMFCSDIDoc::OnMorphologTophat()
	{
		Mat J;
		CImage2Mat(J,img);
		Mat2CImage(J,imgprv[_pic]);
		if(J.step[1]==3)
		{	
			cvtColor( J, J, CV_BGR2GRAY );
			J.convertTo(J,CV_8UC1);
		}
		Mat kern = Mat::ones(33,68,CV_8UC1);
		Mat tmp;
		for(int i=0 ; i<1 ;i++)	
			erode(J,tmp,kern);
		for(int i=0 ; i<1 ;i++)	
			dilate(tmp,tmp,kern);
		J = J-tmp;
		Mat2CImage(J,img);
		UpdateAllViews(0); _pic ++;

	}

	void CMFCSDIDoc::ZOOMDBCLICK(CPoint ptr)
	{
		Mat J;
		CImage2Mat(J,img);
		Mat2CImage(J,imgprv[_pic]);
		int x=0,y=0,w=0,h=0;
		x = (ptr.x/2);
		y = (ptr.y/2);

		if((x+2*x)>J.cols)
			w = J.cols - x;
		else
			w = 2*x;

		if((y+2*y)>J.rows)
			h = J.rows - y;
		else
			h = 2*y;

		J = J(Rect(x,y,w,h));

		Mat2CImage(J,img);
		UpdateAllViews(0); _pic ++;

	}

	void CMFCSDIDoc::OnMorphologSkeleton()
	{
		Mat J;
		CImage2Mat(J,img);
		Mat2CImage(J,imgprv[_pic]);
		if(J.step[1]==3)
		{	
			cvtColor( J, J, CV_BGR2GRAY );
			J.convertTo(J,CV_8UC1);
		}

		Mat kern = Mat::ones(3,3,CV_8UC1);
		Mat tmp ;
		Mat tmpp = J;
		Mat _OUT ;
		Scalar DCD;
		int tsh = J.cols*J.rows*3.2;
t1:
		erode(tmpp,tmp,kern);
		DCD = sum(tmp);
		if((DCD.val[0])>tsh)
		{tmpp = tmp;
		goto t1;
		}
		erode(tmpp,J,kern);
		dilate(J,J,kern);
		_OUT = tmpp - J ;

		Mat2CImage(_OUT,img);
		UpdateAllViews(0); _pic ++;
	}

	void CMFCSDIDoc::OnProjectFocusing()
	{
		Mat J;
		CImage2Mat(J,img);
		Mat2CImage(J,imgprv[_pic]);
		if(J.step[1]==3)
		{	
			cvtColor( J, J, CV_BGR2GRAY );
			J.convertTo(J,CV_8UC1);
		}
		Mat res = Mat::zeros(J.size(),CV_8UC1);
		int limity = J.rows - 1;
		int limitx = J.cols - 1;

		float pi = CV_PI;
		float tm = 75;
		float tp = float(pi/2);
		float eps = float(pi);

		float max=0,min=0;

		for(int j=1 ; j<limity;j++)
		{
			uchar *crt = J.ptr<uchar>(j);
			uchar *nxt = J.ptr<uchar>(j+1);
			uchar *prv = J.ptr<uchar>(j-1);
			uchar *data = res.ptr<uchar>(j);
			for(int i=1; i<limitx;i++)
			{
				float gy = float(prv[i+1] + 2*crt[i+1] + nxt[i+1] - nxt[i-1] - 2*crt[i-1] - prv[i-1]);
				float gx = float(2*nxt[i] + nxt[i+1] + nxt[i-1] - prv[i-1] - 2*prv[i] - prv[i+1]);
				float mag = sqrt(pow(float(gx),2) + pow(float(gy),2)) ;
				float phas = atan(float(gy/gx));
				if(mag>tm)
					if(abs(abs(phas)-tp)<eps)
						data[i] = 255;
			}
		}

		
		Mat kern = Mat::ones(3,3,CV_8UC1);
		erode(res,res,kern);
		dilate(res,res,kern);
		
		Mat resp;

		kern = Mat::ones(50,50,CV_32FC1);
		kern = kern /(kern.rows*kern.cols);
		filter2D(res,resp,res.depth(),kern);
		threshold(resp,resp,5,255,res.type());

		Mat xx;
		xx = resp*0.5 + J*0.5;
		imshow("DECICE",xx);
		
		
		Mat JRES ;
		JRES.create(res.size(),res.type());

		for( int klm =0 ; klm <20 ;klm ++)
		for(int j=1; j<limity;j++)
		{
			uchar *decide = resp.ptr<uchar>(j);
			
			uchar *out = JRES.ptr<uchar>(j);
			uchar *prv = J.ptr<uchar>(j-1);
			uchar *crt = J.ptr<uchar>(j);
			uchar *nxt = J.ptr<uchar>(j+1);
			float prmik ;
			for(int i=0; i<limitx;i++)
				{if(decide[i] <200)
				out[i] = float(9*crt[i] - crt[i-1] - crt[i+1] - prv[i] - prv[i-1] - prv[i+1] - nxt[i] - nxt[i-1] - nxt[i+1] );
				else 
					out[i] = crt[i] ;
				}
		}
		Mat2CImage(JRES,img);
		UpdateAllViews(0); _pic ++;
		
	}
