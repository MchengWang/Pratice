<template>
	<div class="main-content" :style='{"padding":"0"}'>
		<!-- 列表页 -->
		<template v-if="showFlag">
			<el-form class="center-form-pv" :style='{"width":"94%","margin":"30px 3%"}' :inline="true" :model="searchForm">
				<el-row :style='{"display":"block"}' >
					<div :style='{"margin":"0 20px 0 0","display":"inline-block"}'>
						<label :style='{"margin":"0 10px 0 0","color":"#333","display":"inline-block","lineHeight":"40px","fontSize":"14px","fontWeight":"500","height":"40px"}' class="item-label">地区名</label>
						<el-input v-model="searchForm.cunming" placeholder="地区名" clearable></el-input>
					</div>
					<div :style='{"margin":"0 20px 0 0","display":"inline-block"}'>
						<label :style='{"margin":"0 10px 0 0","color":"#333","display":"inline-block","lineHeight":"40px","fontSize":"14px","fontWeight":"500","height":"40px"}' class="item-label">户主姓名</label>
						<el-input v-model="searchForm.huzhuxingming" placeholder="户主姓名" clearable></el-input>
					</div>
					<div :style='{"margin":"0 20px 0 0","display":"inline-block"}'>
						<label :style='{"margin":"0 10px 0 0","color":"#333","display":"inline-block","lineHeight":"40px","fontSize":"14px","fontWeight":"500","height":"40px"}' class="item-label">家庭地址</label>
						<el-input v-model="searchForm.jiatingdizhi" placeholder="家庭地址" clearable></el-input>
					</div>
					<div :style='{"margin":"0 20px 0 0","display":"inline-block"}' class="select" label="贫困状况" prop="pinkunzhuangkuang">
						<label :style='{"margin":"0 10px 0 0","color":"#333","display":"inline-block","lineHeight":"40px","fontSize":"14px","fontWeight":"500","height":"40px"}' class="item-label">贫困状况</label>
						<el-select  @change="pinkunzhuangkuangChange" clearable v-model="searchForm.pinkunzhuangkuang" placeholder="请选择贫困状况">
							<el-option v-for="(item,index) in pinkunzhuangkuangOptions" v-bind:key="index" :label="item" :value="item"></el-option>
						</el-select>
					</div>
					<div :style='{"margin":"0 20px 0 0","display":"inline-block"}' class="select" label="致贫原因" prop="zhipinyuanyin">
						<label :style='{"margin":"0 10px 0 0","color":"#333","display":"inline-block","lineHeight":"40px","fontSize":"14px","fontWeight":"500","height":"40px"}' class="item-label">致贫原因</label>
						<el-select  @change="zhipinyuanyinChange" clearable v-model="searchForm.zhipinyuanyin" placeholder="请选择致贫原因">
							<el-option v-for="(item,index) in zhipinyuanyinOptions" v-bind:key="index" :label="item" :value="item"></el-option>
						</el-select>
					</div>
					<el-button :style='{"border":"0","cursor":"pointer","padding":"0 24px","outline":"none","color":"#fff","borderRadius":"4px","background":"rgba(165, 155, 149, 1)","width":"auto","fontSize":"14px","height":"40px"}' type="success" @click="search()">查询</el-button>
				</el-row>

				<el-row :style='{"margin":"20px 0","justifyContent":"flex-end","display":"flex"}'>
					<el-button :style='{"border":"0","cursor":"pointer","padding":"0 24px","margin":"0 10px 0 0","outline":"none","color":"#fff","borderRadius":"4px","background":"rgba(182, 179, 178, 1)","width":"auto","fontSize":"14px","height":"40px"}' v-if="isAuth('pinkunhu','新增')" type="success" @click="addOrUpdateHandler()">新增</el-button>
					<el-button :style='{"border":"0","cursor":"pointer","padding":"0 24px","margin":"0 10px 0 0","outline":"none","color":"#fff","borderRadius":"4px","background":"rgba(182, 179, 178, 1)","width":"auto","fontSize":"14px","height":"40px"}' v-if="isAuth('pinkunhu','删除')" :disabled="dataListSelections.length <= 0" type="danger" @click="deleteHandler()">删除</el-button>




					<el-button :style='{"border":"0","cursor":"pointer","padding":"0 24px","margin":"0 10px 0 0","outline":"none","color":"#fff","borderRadius":"4px","background":"rgba(182, 179, 178, 1)","width":"auto","fontSize":"14px","height":"40px"}' v-if="isAuth('pinkunhu','贫困状况统计')" type="warning" @click="chartDialog1()">贫困状况统计</el-button>
					<el-button :style='{"border":"0","cursor":"pointer","padding":"0 24px","margin":"0 10px 0 0","outline":"none","color":"#fff","borderRadius":"4px","background":"rgba(182, 179, 178, 1)","width":"auto","fontSize":"14px","height":"40px"}' v-if="isAuth('pinkunhu','风险标准占比')" type="warning" @click="chartDialog2()">风险标准占比</el-button>
				</el-row>
			</el-form>
			
			<!-- <div> -->
				<el-table class="tables"
					:stripe='false'
					:style='{"padding":"0","borderColor":"#eee","margin":"30px 3%","borderWidth":"1px 0 0 1px","background":"#fff","width":"94%","borderStyle":"solid"}' 
					v-if="isAuth('pinkunhu','查看')"
					:data="dataList"
					v-loading="dataListLoading"
				@selection-change="selectionChangeHandler">
					<el-table-column :resizable='true' type="selection" align="center" width="50"></el-table-column>
					<el-table-column :resizable='true' :sortable='true' label="索引" type="index" width="50" />
					<el-table-column :resizable='true' :sortable='true'  
						prop="cunming"
					label="地区名">
						<template slot-scope="scope">
							{{scope.row.cunming}}
						</template>
					</el-table-column>
					<el-table-column :resizable='true' :sortable='true'  
						prop="huzhuxingming"
					label="户主姓名">
						<template slot-scope="scope">
							{{scope.row.huzhuxingming}}
						</template>
					</el-table-column>
					<el-table-column :resizable='true' :sortable='true'  
						prop="jiatingdizhi"
					label="家庭地址">
						<template slot-scope="scope">
							{{scope.row.jiatingdizhi}}
						</template>
					</el-table-column>
					<el-table-column :resizable='true' :sortable='true'  
						prop="jiatingrenshu"
					label="家庭人数">
						<template slot-scope="scope">
							{{scope.row.jiatingrenshu}}
						</template>
					</el-table-column>
					<el-table-column :resizable='true' :sortable='true'  
						prop="pinkunzhuangkuang"
					label="贫困状况">
						<template slot-scope="scope">
							{{scope.row.pinkunzhuangkuang}}
						</template>
					</el-table-column>
					<el-table-column :resizable='true' :sortable='true'  
						prop="renjunshouru"
					label="人均收入">
						<template slot-scope="scope">
							{{scope.row.renjunshouru}}
						</template>
					</el-table-column>
					<el-table-column :resizable='true' :sortable='true'  
						prop="jiatingzhichu"
					label="家庭支出">
						<template slot-scope="scope">
							{{scope.row.jiatingzhichu}}
						</template>
					</el-table-column>
					<el-table-column :resizable='true' :sortable='true'  
						prop="zhipinyuanyin"
					label="致贫原因">
						<template slot-scope="scope">
							{{scope.row.zhipinyuanyin}}
						</template>
					</el-table-column>
					<el-table-column :resizable='true' :sortable='true'  
						prop="dengjishijian"
					label="登记时间">
						<template slot-scope="scope">
							{{scope.row.dengjishijian}}
						</template>
					</el-table-column>
					<el-table-column width="300" label="操作">
						<template slot-scope="scope">
							<el-button :style='{"border":"5px solid #CFD5F8","cursor":"pointer","padding":"0 24px","margin":"0 10px 5px 0","outline":"none","color":"#999","borderRadius":"30px","background":"rgba(255, 255, 255, 1)","width":"auto","fontSize":"14px","height":"40px"}' v-if=" isAuth('pinkunhu','查看')" type="success" size="mini" @click="addOrUpdateHandler(scope.row.id,'info')">详情</el-button>
							<el-button :style='{"border":"5px solid #CFD5F8","cursor":"pointer","padding":"0 24px","margin":"0 10px 5px 0","outline":"none","color":"#999","borderRadius":"30px","background":"rgba(255, 255, 255, 1)","width":"auto","fontSize":"14px","height":"40px"}' v-if="isAuth('pinkunhu','添加成员')" type="success" size="mini" @click="jiatingchengyuanCrossAddOrUpdateHandler(scope.row,'cross','','','')">添加成员</el-button>
							<el-button :style='{"border":"5px solid #CFD5F8","cursor":"pointer","padding":"0 24px","margin":"0 10px 5px 0","outline":"none","color":"#999","borderRadius":"30px","background":"rgba(255, 255, 255, 1)","width":"auto","fontSize":"14px","height":"40px"}' v-if="isAuth('pinkunhu','帮扶结对')" type="success" size="mini" @click="bangfujieduiCrossAddOrUpdateHandler(scope.row,'cross','','','')">帮扶结对</el-button>
							<el-button :style='{"border":"5px solid #CFD5F8","cursor":"pointer","padding":"0 24px","margin":"0 10px 5px 0","outline":"none","color":"#999","borderRadius":"30px","background":"rgba(255, 255, 255, 1)","width":"auto","fontSize":"14px","height":"40px"}' v-if="isAuth('pinkunhu','调研')" type="success" size="mini" @click="pinkundiaoyanCrossAddOrUpdateHandler(scope.row,'cross','','[1]','已经调研了')">调研</el-button>
							<el-button :style='{"border":"5px solid #CFD5F8","cursor":"pointer","padding":"0 24px","margin":"0 10px 5px 0","outline":"none","color":"#999","borderRadius":"30px","background":"rgba(255, 255, 255, 1)","width":"auto","fontSize":"14px","height":"40px"}' v-if=" isAuth('pinkunhu','修改')" type="primary" size="mini" @click="addOrUpdateHandler(scope.row.id)">修改</el-button>





							<el-button :style='{"border":"5px solid #CFD5F8","cursor":"pointer","padding":"0 24px","margin":"0 10px 5px 0","outline":"none","color":"#999","borderRadius":"30px","background":"rgba(255, 255, 255, 1)","width":"auto","fontSize":"14px","height":"40px"}' v-if="isAuth('pinkunhu','删除') " type="danger" size="mini" @click="deleteHandler(scope.row.id)">删除</el-button>
						</template>
					</el-table-column>
				</el-table>
				<el-pagination
					@size-change="sizeChangeHandle"
					@current-change="currentChangeHandle"
					:current-page="pageIndex"
					background
					:page-sizes="[10, 20, 30, 50]"
					:page-size="pageSize"
					:layout="layouts.join()"
					:total="totalPage"
					prev-text="<"
					next-text=">"
					:hide-on-single-page="false"
					:style='{"padding":"0","margin":"20px 0","whiteSpace":"nowrap","color":"#333","textAlign":"center","width":"100%","fontWeight":"500"}'
				></el-pagination>
			<!-- </div> -->
		</template>
		
		<!-- 添加/修改页面  将父组件的search方法传递给子组件-->
		<add-or-update v-if="addOrUpdateFlag" :parent="this" ref="addOrUpdate"></add-or-update>

		<jiatingchengyuan-cross-add-or-update v-if="jiatingchengyuanCrossAddOrUpdateFlag" :parent="this" ref="jiatingchengyuanCrossaddOrUpdate"></jiatingchengyuan-cross-add-or-update>
		<bangfujiedui-cross-add-or-update v-if="bangfujieduiCrossAddOrUpdateFlag" :parent="this" ref="bangfujieduiCrossaddOrUpdate"></bangfujiedui-cross-add-or-update>
		<pinkundiaoyan-cross-add-or-update v-if="pinkundiaoyanCrossAddOrUpdateFlag" :parent="this" ref="pinkundiaoyanCrossaddOrUpdate"></pinkundiaoyan-cross-add-or-update>




		<el-dialog
		  title="贫困状况统计"
		  :visible.sync="chartVisiable1"
		  width="800">
			<div id="pinkunzhuangkuangChart1" style="width:100%;height:600px;"></div>
		  <span slot="footer" class="dialog-footer">
			<el-button @click="chartDialog1">返回</el-button>
		  </span>
		</el-dialog>
		<el-dialog
		  title="风险标准占比"
		  :visible.sync="chartVisiable2"
		  width="800">
			<div id="zhipinyuanyinChart2" style="width:100%;height:600px;"></div>
		  <span slot="footer" class="dialog-footer">
			<el-button @click="chartDialog2">返回</el-button>
		  </span>
		</el-dialog>
	</div>
</template>

<script>
import * as echarts from 'echarts'
import axios from 'axios'
import AddOrUpdate from "./add-or-update";
import jiatingchengyuanCrossAddOrUpdate from "../jiatingchengyuan/add-or-update";
import bangfujieduiCrossAddOrUpdate from "../bangfujiedui/add-or-update";
import pinkundiaoyanCrossAddOrUpdate from "../pinkundiaoyan/add-or-update";
export default {
  data() {
    return {
      searchForm: {
        key: ""
      },
      form:{},
      dataList: [],
      pageIndex: 1,
      pageSize: 10,
      totalPage: 0,
      dataListLoading: false,
      dataListSelections: [],
      showFlag: true,
      sfshVisiable: false,
      shForm: {},
      chartVisiable: false,
      chartVisiable1: false,
      chartVisiable2: false,
      chartVisiable3: false,
      chartVisiable4: false,
      chartVisiable5: false,
      addOrUpdateFlag:false,
      jiatingchengyuanCrossAddOrUpdateFlag: false,
      bangfujieduiCrossAddOrUpdateFlag: false,
      pinkundiaoyanCrossAddOrUpdateFlag: false,
      layouts: ["total","prev","pager","next","sizes","jumper"],

    };
  },
  created() {
    this.init();
    this.getDataList();
    this.contentStyleChange()
  },
  mounted() {
  },
  filters: {
    htmlfilter: function (val) {
      return val.replace(/<[^>]*>/g).replace(/undefined/g,'');
    }
  },
  components: {
    AddOrUpdate,
    jiatingchengyuanCrossAddOrUpdate,
    bangfujieduiCrossAddOrUpdate,
    pinkundiaoyanCrossAddOrUpdate,
  },
  methods: {

    contentStyleChange() {
      this.contentPageStyleChange()
    },
    // 分页
    contentPageStyleChange(){
      let arr = []

      // if(this.contents.pageTotal) arr.push('total')
      // if(this.contents.pageSizes) arr.push('sizes')
      // if(this.contents.pagePrevNext){
      //   arr.push('prev')
      //   if(this.contents.pagePager) arr.push('pager')
      //   arr.push('next')
      // }
      // if(this.contents.pageJumper) arr.push('jumper')
      // this.layouts = arr.join()
      // this.contents.pageEachNum = 10
    },

    jiatingchengyuanCrossAddOrUpdateHandler(row,type,crossOptAudit,statusColumnName,tips,statusColumnValue){
      this.showFlag = false;
      this.addOrUpdateFlag = false;
      this.jiatingchengyuanCrossAddOrUpdateFlag = true;
      this.$storage.set('crossObj',row);
      this.$storage.set('crossTable','pinkunhu');
      this.$storage.set('statusColumnName',statusColumnName);
      this.$storage.set('statusColumnValue',statusColumnValue);
      this.$storage.set('tips',tips);
	if(statusColumnName!=''&&!statusColumnName.startsWith("[")) {
		var obj = this.$storage.getObj('crossObj');
		for (var o in obj){
		  if(o==statusColumnName && obj[o]==statusColumnValue){
		    this.$message({
		      message: tips,
		      type: "success",
		      duration: 1500,
		      onClose: () => {
			this.getDataList();
		      }
		    });
		      this.showFlag = true;
		      this.jiatingchengyuanCrossAddOrUpdateFlag = false;
			return;
		  }
		}
	}
      this.$nextTick(() => {
      this.$refs.jiatingchengyuanCrossaddOrUpdate.init(row.id,type);
      });
    },
    bangfujieduiCrossAddOrUpdateHandler(row,type,crossOptAudit,statusColumnName,tips,statusColumnValue){
      this.showFlag = false;
      this.addOrUpdateFlag = false;
      this.bangfujieduiCrossAddOrUpdateFlag = true;
      this.$storage.set('crossObj',row);
      this.$storage.set('crossTable','pinkunhu');
      this.$storage.set('statusColumnName',statusColumnName);
      this.$storage.set('statusColumnValue',statusColumnValue);
      this.$storage.set('tips',tips);
	if(statusColumnName!=''&&!statusColumnName.startsWith("[")) {
		var obj = this.$storage.getObj('crossObj');
		for (var o in obj){
		  if(o==statusColumnName && obj[o]==statusColumnValue){
		    this.$message({
		      message: tips,
		      type: "success",
		      duration: 1500,
		      onClose: () => {
			this.getDataList();
		      }
		    });
		      this.showFlag = true;
		      this.bangfujieduiCrossAddOrUpdateFlag = false;
			return;
		  }
		}
	}
      this.$nextTick(() => {
      this.$refs.bangfujieduiCrossaddOrUpdate.init(row.id,type);
      });
    },
    pinkundiaoyanCrossAddOrUpdateHandler(row,type,crossOptAudit,statusColumnName,tips,statusColumnValue){
      this.showFlag = false;
      this.addOrUpdateFlag = false;
      this.pinkundiaoyanCrossAddOrUpdateFlag = true;
      this.$storage.set('crossObj',row);
      this.$storage.set('crossTable','pinkunhu');
      this.$storage.set('statusColumnName',statusColumnName);
      this.$storage.set('statusColumnValue',statusColumnValue);
      this.$storage.set('tips',tips);
	if(statusColumnName!=''&&!statusColumnName.startsWith("[")) {
		var obj = this.$storage.getObj('crossObj');
		for (var o in obj){
		  if(o==statusColumnName && obj[o]==statusColumnValue){
		    this.$message({
		      message: tips,
		      type: "success",
		      duration: 1500,
		      onClose: () => {
			this.getDataList();
		      }
		    });
		      this.showFlag = true;
		      this.pinkundiaoyanCrossAddOrUpdateFlag = false;
			return;
		  }
		}
	}
      this.$nextTick(() => {
      this.$refs.pinkundiaoyanCrossaddOrUpdate.init(row.id,type);
      });
    },


//统计接口
    chartDialog1() {
      this.chartVisiable1 = !this.chartVisiable1;
      this.$nextTick(()=>{

        var pinkunzhuangkuangChart1 = echarts.init(document.getElementById("pinkunzhuangkuangChart1"),'dark-bold');
        this.$http({
            url: "pinkunhu/group/pinkunzhuangkuang",
            method: "get",
        }).then(({ data }) => {
            if (data && data.code === 0) {
                let res = data.data;
                let xAxis = [];
                let yAxis = [];
                let pArray = []
                for(let i=0;i<res.length;i++){
                    xAxis.push(res[i].pinkunzhuangkuang);
                    yAxis.push(parseFloat((res[i].total)));
                    pArray.push({
                        value: parseFloat((res[i].total)),
                        name: res[i].pinkunzhuangkuang
                    })
                }
                var option = {};
                option = {
                        title: {
                            text: '贫困状况统计',
                            left: 'center'
                        },
                        legend: {
                          orient: 'vertical',
                          left: 'left'
                        },
                        tooltip: {
                          trigger: 'item',
                          formatter: '{b} : {c} ({d}%)'
                        },
                        series: [
                            {
                                type: 'pie',
                                radius: ['25%', '55%'],
                                center: ['50%', '60%'],
                                data: pArray,
                                emphasis: {
                                    itemStyle: {
                                        shadowBlur: 10,
                                        shadowOffsetX: 0,
                                        shadowColor: 'rgba(0, 0, 0, 0.5)'
                                    }
                                }
                            }
                        ]
                };
                // 使用刚指定的配置项和数据显示图表。
                pinkunzhuangkuangChart1.setOption(option);
                  //根据窗口的大小变动图表
                window.onresize = function() {
                    pinkunzhuangkuangChart1.resize();
                };
            }
        });
      })
    },

//统计接口
    chartDialog2() {
      this.chartVisiable2 = !this.chartVisiable2;
      this.$nextTick(()=>{

        var zhipinyuanyinChart2 = echarts.init(document.getElementById("zhipinyuanyinChart2"),'dark-bold');
        this.$http({
            url: "pinkunhu/group/zhipinyuanyin",
            method: "get",
        }).then(({ data }) => {
            if (data && data.code === 0) {
                let res = data.data;
                let xAxis = [];
                let yAxis = [];
                let pArray = []
                for(let i=0;i<res.length;i++){
                    xAxis.push(res[i].zhipinyuanyin);
                    yAxis.push(parseFloat((res[i].total)));
                    pArray.push({
                        value: parseFloat((res[i].total)),
                        name: res[i].zhipinyuanyin
                    })
                }
                var option = {};
                option = {
                    title: {
                        text: '风险标准占比',
                        left: 'center'
                    },
                    tooltip: {
                      trigger: 'item',
                      formatter: '{b} : {c}'
                    },
                    xAxis: {
                        type: 'category',
                        data: xAxis
                    },
                    yAxis: {
                        type: 'value'
                    },
                    series: [{
                        data: yAxis,
                        type: 'bar'
                    }]
                };
                // 使用刚指定的配置项和数据显示图表。
                zhipinyuanyinChart2.setOption(option);
                  //根据窗口的大小变动图表
                window.onresize = function() {
                    zhipinyuanyinChart2.resize();
                };
            }
        });
      })
    },




    init () {
          this.pinkunzhuangkuangOptions = "待审核,贫困,脱贫,返贫".split(',')
          this.zhipinyuanyinOptions = "因学致贫,因灾致贫,收入降低致贫,其他".split(',')
    },
    search() {
      this.pageIndex = 1;
      this.getDataList();
    },

    // 获取数据列表
    getDataList() {
      this.dataListLoading = true;
      let params = {
        page: this.pageIndex,
        limit: this.pageSize,
        sort: 'id',
        order: 'desc',
      }
           if(this.searchForm.cunming!='' && this.searchForm.cunming!=undefined){
            params['cunming'] = '%' + this.searchForm.cunming + '%'
          }
           if(this.searchForm.huzhuxingming!='' && this.searchForm.huzhuxingming!=undefined){
            params['huzhuxingming'] = '%' + this.searchForm.huzhuxingming + '%'
          }
           if(this.searchForm.jiatingdizhi!='' && this.searchForm.jiatingdizhi!=undefined){
            params['jiatingdizhi'] = '%' + this.searchForm.jiatingdizhi + '%'
          }
           if(this.searchForm.pinkunzhuangkuang!='' && this.searchForm.pinkunzhuangkuang!=undefined){
            params['pinkunzhuangkuang'] = this.searchForm.pinkunzhuangkuang
          }
           if(this.searchForm.zhipinyuanyin!='' && this.searchForm.zhipinyuanyin!=undefined){
            params['zhipinyuanyin'] = this.searchForm.zhipinyuanyin
          }
      this.$http({
        url: "pinkunhu/page",
        method: "get",
        params: params
      }).then(({ data }) => {
        if (data && data.code === 0) {
          this.dataList = data.data.list;
          this.totalPage = data.data.total;
        } else {
          this.dataList = [];
          this.totalPage = 0;
        }
        this.dataListLoading = false;
      });
    },
    // 每页数
    sizeChangeHandle(val) {
      this.pageSize = val;
      this.pageIndex = 1;
      this.getDataList();
    },
    // 当前页
    currentChangeHandle(val) {
      this.pageIndex = val;
      this.getDataList();
    },
    // 多选
    selectionChangeHandler(val) {
      this.dataListSelections = val;
    },
    // 添加/修改
    addOrUpdateHandler(id,type) {
      this.showFlag = false;
      this.addOrUpdateFlag = true;
      this.crossAddOrUpdateFlag = false;
      if(type!='info'){
        type = 'else';
      }
      this.$nextTick(() => {
        this.$refs.addOrUpdate.init(id,type);
      });
    },
    // 下载
    download(file){
      window.open(`${file}`)
    },
    // 删除
    deleteHandler(id) {
      var ids = id
        ? [Number(id)]
        : this.dataListSelections.map(item => {
            return Number(item.id);
          });
      this.$confirm(`确定进行[${id ? "删除" : "批量删除"}]操作?`, "提示", {
        confirmButtonText: "确定",
        cancelButtonText: "取消",
        type: "warning"
      }).then(() => {
        this.$http({
          url: "pinkunhu/delete",
          method: "post",
          data: ids
        }).then(({ data }) => {
          if (data && data.code === 0) {
            this.$message({
              message: "操作成功",
              type: "success",
              duration: 1500,
              onClose: () => {
                this.search();
              }
            });
          } else {
            this.$message.error(data.msg);
          }
        });
      });
    },


  }

};
</script>
<style lang="scss" scoped>
	
	.center-form-pv {
	  .el-date-editor.el-input {
	    width: auto;
	  }
	}
	
	.el-input {
	  width: auto;
	}
	
	// form
	.center-form-pv .el-input /deep/ .el-input__inner {
				border: 0;
				border-radius: 4px;
				padding: 0 15px;
				box-shadow: 0px 0px 0px 7px rgba(140, 132, 127, 1) inset;
				outline: none;
				color: #fff;
				background: rgba(165, 155, 149, 1);
				width: 170px;
				font-size: 14px;
				height: 45px;
			}
	
	.center-form-pv .el-select /deep/ .el-input__inner {
				border: 0;
				border-radius: 4px;
				padding: 0 15px;
				box-shadow: 0px 0px 0px 7px rgba(140, 132, 127, 1) inset;
				outline: none;
				color: #fff;
				background: rgba(165, 155, 149, 1);
				width: 170px;
				font-size: 14px;
				height: 45px;
			}
	
	.center-form-pv .el-date-editor /deep/ .el-input__inner {
				border: 0;
				border-radius: 4px;
				padding: 0 10px 0 30px;
				box-shadow: 0px 0px 0px 7px rgba(140, 132, 127, 1) inset;
				outline: none;
				color: #fff;
				background: rgba(165, 155, 149, 1);
				width: 170px;
				font-size: 14px;
				height: 45px;
			}
	
	// table
	.el-table /deep/ .el-table__header-wrapper thead {
				color: #333;
				font-weight: 500;
				width: 100%;
			}
	
	.el-table /deep/ .el-table__header-wrapper thead tr {
				background: #fff;
			}
	
	.el-table /deep/ .el-table__header-wrapper thead tr th {
				padding: 12px 0;
				background: rgba(182, 179, 178, 1);
				border-color: #eee;
				border-width: 0 1px 1px 0;
				border-style: solid;
				text-align: center;
			}

	.el-table /deep/ .el-table__header-wrapper thead tr th .cell {
				padding: 0 10px;
				word-wrap: normal;
				word-break: break-all;
				white-space: normal;
				font-weight: bold;
				display: inline-block;
				vertical-align: middle;
				width: 100%;
				line-height: 24px;
				position: relative;
				text-overflow: ellipsis;
			}

	
	.el-table /deep/ .el-table__body-wrapper tbody {
				width: 100%;
			}

	.el-table /deep/ .el-table__body-wrapper tbody tr {
				background: #fff;
			}
	
	.el-table /deep/ .el-table__body-wrapper tbody tr td {
				padding: 12px 0;
				color: #999;
				background: #fff;
				border-color: #eee;
				border-width: 0 1px 1px 0;
				border-style: solid;
				text-align: center;
			}
	
		
	.el-table /deep/ .el-table__body-wrapper tbody tr:hover td {
				padding: 12px 0;
				color: #fff;
				background: rgba(214, 214, 214, 1);
				border-color: #eee;
				border-width: 0 1px 1px 0;
				border-style: solid;
				text-align: center;
			}
	
	.el-table /deep/ .el-table__body-wrapper tbody tr td {
				padding: 12px 0;
				color: #999;
				background: #fff;
				border-color: #eee;
				border-width: 0 1px 1px 0;
				border-style: solid;
				text-align: center;
			}

	.el-table /deep/ .el-table__body-wrapper tbody tr td .cell {
				padding: 0 10px;
				overflow: hidden;
				word-break: break-all;
				white-space: normal;
				line-height: 24px;
				text-overflow: ellipsis;
			}
	
	// pagination
	.main-content .el-pagination /deep/ .el-pagination__total {
				margin: 0 10px 0 0;
				color: #666;
				font-weight: 400;
				display: inline-block;
				vertical-align: top;
				font-size: 13px;
				line-height: 28px;
				height: 28px;
			}
	
	.main-content .el-pagination /deep/ .btn-prev {
				border: none;
				border-radius: 2px;
				padding: 0;
				margin: 0 5px;
				color: #666;
				background: #f4f4f5;
				display: inline-block;
				vertical-align: top;
				font-size: 13px;
				line-height: 28px;
				min-width: 35px;
				height: 28px;
			}
	
	.main-content .el-pagination /deep/ .btn-next {
				border: none;
				border-radius: 2px;
				padding: 0;
				margin: 0 5px;
				color: #666;
				background: #f4f4f5;
				display: inline-block;
				vertical-align: top;
				font-size: 13px;
				line-height: 28px;
				min-width: 35px;
				height: 28px;
			}
	
	.main-content .el-pagination /deep/ .btn-prev:disabled {
				border: none;
				cursor: not-allowed;
				border-radius: 2px;
				padding: 0;
				margin: 0 5px;
				color: #C0C4CC;
				background: #f4f4f5;
				display: inline-block;
				vertical-align: top;
				font-size: 13px;
				line-height: 28px;
				height: 28px;
			}
	
	.main-content .el-pagination /deep/ .btn-next:disabled {
				border: none;
				cursor: not-allowed;
				border-radius: 2px;
				padding: 0;
				margin: 0 5px;
				color: #C0C4CC;
				background: #f4f4f5;
				display: inline-block;
				vertical-align: top;
				font-size: 13px;
				line-height: 28px;
				height: 28px;
			}

	.main-content .el-pagination /deep/ .el-pager {
				padding: 0;
				margin: 0;
				display: inline-block;
				vertical-align: top;
			}

	.main-content .el-pagination /deep/ .el-pager .number {
				cursor: pointer;
				padding: 0 4px;
				margin: 0 5px;
				color: #666;
				display: inline-block;
				vertical-align: top;
				font-size: 13px;
				line-height: 28px;
				border-radius: 2px;
				background: #f4f4f5;
				text-align: center;
				min-width: 30px;
				height: 28px;
			}
	
	.main-content .el-pagination /deep/ .el-pager .number:hover {
				cursor: pointer;
				padding: 0 4px;
				margin: 0 5px;
				color: #333;
				display: inline-block;
				vertical-align: top;
				font-size: 13px;
				line-height: 28px;
				border-radius: 2px;
				background: #f4f4f5;
				text-align: center;
				min-width: 30px;
				height: 28px;
			}
	
	.main-content .el-pagination /deep/ .el-pager .number.active {
				cursor: default;
				padding: 0 4px;
				margin: 0 5px;
				color: #FFF;
				display: inline-block;
				vertical-align: top;
				font-size: 13px;
				line-height: 28px;
				border-radius: 2px;
				background: rgba(182, 179, 178, 1);
				text-align: center;
				min-width: 30px;
				height: 28px;
			}
	
	.main-content .el-pagination /deep/ .el-pagination__sizes {
				display: inline-block;
				vertical-align: top;
				font-size: 13px;
				line-height: 28px;
				height: 28px;
			}
	
	.main-content .el-pagination /deep/ .el-pagination__sizes .el-input {
				margin: 0 5px;
				width: 100px;
				position: relative;
			}
	
	.main-content .el-pagination /deep/ .el-pagination__sizes .el-input .el-input__inner {
				border: 1px solid #DCDFE6;
				cursor: pointer;
				padding: 0 25px 0 8px;
				color: #606266;
				display: inline-block;
				font-size: 13px;
				line-height: 28px;
				border-radius: 3px;
				outline: 0;
				background: #FFF;
				width: 100%;
				text-align: center;
				height: 28px;
			}
	
	.main-content .el-pagination /deep/ .el-pagination__sizes .el-input span.el-input__suffix {
				top: 0;
				position: absolute;
				right: 0;
				height: 100%;
			}
	
	.main-content .el-pagination /deep/ .el-pagination__sizes .el-input .el-input__suffix .el-select__caret {
				cursor: pointer;
				color: #C0C4CC;
				width: 25px;
				font-size: 14px;
				line-height: 28px;
				text-align: center;
			}
	
	.main-content .el-pagination /deep/ .el-pagination__jump {
				margin: 0 0 0 24px;
				color: #606266;
				display: inline-block;
				vertical-align: top;
				font-size: 13px;
				line-height: 28px;
				height: 28px;
			}
	
	.main-content .el-pagination /deep/ .el-pagination__jump .el-input {
				border-radius: 3px;
				padding: 0 2px;
				margin: 0 2px;
				display: inline-block;
				width: 50px;
				font-size: 14px;
				line-height: 18px;
				position: relative;
				text-align: center;
				height: 28px;
			}
	
	.main-content .el-pagination /deep/ .el-pagination__jump .el-input .el-input__inner {
				border: 1px solid #DCDFE6;
				cursor: pointer;
				padding: 0 3px;
				color: #606266;
				display: inline-block;
				font-size: 14px;
				line-height: 28px;
				border-radius: 3px;
				outline: 0;
				background: #FFF;
				width: 100%;
				text-align: center;
				height: 28px;
			}
</style>
