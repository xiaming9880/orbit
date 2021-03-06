//-----------------------------------
// Copyright Pierric Gimmig 2013-2017
//-----------------------------------
#pragma once

#include "DataView.h"
#include "OrbitType.h"

class FunctionsDataView : public DataView {
 public:
  FunctionsDataView();

  const std::vector<std::wstring>& GetColumnHeaders() override;
  const std::vector<float>& GetColumnHeadersRatios() override;
  const std::vector<SortingOrder>& GetColumnInitialOrders() override;
  int GetDefaultSortingColumn() override;
  std::vector<std::wstring> GetContextMenu(int a_Index) override;
  std::wstring GetValue(int a_Row, int a_Column) override;
  void OnFilter(const std::wstring& a_Filter) override;
  void ParallelFilter();
  void OnSort(int a_Column, std::optional<SortingOrder> a_NewOrder) override;
  void OnContextMenu(const std::wstring& a_Action, int a_MenuIndex,
                     std::vector<int>& a_ItemIndices) override;
  void OnDataChanged() override;

 protected:
  virtual Function& GetFunction(unsigned int a_Row);

  std::vector<std::wstring> m_FilterTokens;

  static void InitColumnsIfNeeded();
  static std::vector<std::wstring> s_Headers;
  static std::vector<int> s_HeaderMap;
  static std::vector<float> s_HeaderRatios;
  static std::vector<SortingOrder> s_InitialOrders;
};
