
// MFC-SDIDoc.h : interface of the CMFCSDIDoc class
//


#pragma once

class CMFCSDIDoc : public CDocument
{
protected: // create from serialization only
	CMFCSDIDoc();
	DECLARE_DYNCREATE(CMFCSDIDoc)

// Attributes
public:

// Operations
public:


// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CMFCSDIDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	
// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	CImage img;
	CImage imgprv[10];
	afx_msg void OnFilterBlur();
	afx_msg void OnFilterSharp();
	afx_msg void OnGeneralUndo();
	afx_msg void OnShrink();
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
	afx_msg void OnFileSave();
	afx_msg void OnGeneralusageDo();
	afx_msg void ONBITPLANE();
	afx_msg void Hist();


	afx_msg void OnFilterZoom();
	afx_msg void OnDetectionComponent();
	afx_msg void OnFrquencyMag();
	afx_msg void OnFrquencyLowpassfilter();
	afx_msg void OnFrquencyHighpassfilter();
	afx_msg void OnHistHist();
	afx_msg void OnHistHist32784();
	afx_msg void OnHistHist32785();
	afx_msg void OnHistHist32786();
	afx_msg void OnHistLocal();
	afx_msg void OnEnhancementMedian();
	afx_msg void OnEnhancementGaussian();
	afx_msg void OnDetectionLaplacian();
	afx_msg void OnDetectionGradient();
	afx_msg void OnFuzzyEdge();
	afx_msg	void zweix();
	afx_msg	void vierx();
	afx_msg	void ein();
	afx_msg	void minus();
	afx_msg void OnFuzzyIntensity();
	afx_msg void OnEnhancementGamma();
	afx_msg void OnEnhancementLinear();
	afx_msg void OnAliasingChessboard();
	afx_msg void OnFrquencyLowpassfilter32814();
	afx_msg void OnFrquencyLowpassfilter32815();
	afx_msg void OnFrquencyHomomorphic();
	afx_msg void OnFrquencyLaplacian();
	afx_msg void OnFrquencyRotate();
	afx_msg void OnFrquencyCorelation();
	afx_msg void OnProjectFocusing();
	afx_msg void OnEnhancementGeometric();
	afx_msg void OnEnhancementArithmean();
	afx_msg void OnEnhancementAdaptivemedian();
	afx_msg void OnEnhancementContraharmonic();
	afx_msg void OnEnhancementMidpoi();
	afx_msg void OnEnhancementAlpha();
	afx_msg void OnEnhancementPeriodicnoise();
	afx_msg void OnFrquencyMagview();
	afx_msg void OnEnhancementRingfilter();
	afx_msg void OnEnhancementNotchfilter();
	afx_msg void OnEnhancementAtomsphericturb();
	afx_msg void OnEnhancementMotionblur();
	afx_msg void OnColorfullFalsecolor();
	afx_msg void OnColorfullBoostingcont();
	afx_msg void OnColorfullNegative();
	afx_msg void OnColorfullExtraction();
	afx_msg void OnColorfullEqualization();
	afx_msg void OnColorfullHsi();
	afx_msg void OnColorfullEdgedetection();
	afx_msg void OnEnhancementGeometrictrans();
	afx_msg void OnWaveletDebuachi();
	afx_msg void OnMorphologDilation();
	afx_msg void OnMorphologErotion();
	afx_msg void OnMorphologOpening();
	afx_msg void OnMorphologClosing();
	afx_msg void OnMorpholog32850();
	afx_msg void OnMorphologHitormiss();
	afx_msg void OnMorphologBoundaryextrac();
	afx_msg void OnMorphologRegionfilling();
	afx_msg void OnSegmentationLinking();
	afx_msg void OnSegmentationLinedetec();
	afx_msg void OnSegmentationCircledetec();
	afx_msg void OnMorphologConvex();
	afx_msg void OnEnhancementInversefilt();
	afx_msg void OnEnhancementMotionblurspat();
	afx_msg void OnMorphologTophat();
	afx_msg void ZOOMDBCLICK(CPoint ptr);
	afx_msg void OnMorphologSkeleton();
};
