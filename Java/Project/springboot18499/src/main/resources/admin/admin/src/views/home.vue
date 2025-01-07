<template>
<div class="content" :style='{"padding":"30px"}'>
	<div class="text" :style='{"margin":"50px auto","fontSize":"24px","color":"rgb(51, 51, 51)","textAlign":"center","fontWeight":"bold"}'>欢迎使用 {{this.$project.projectName}}</div>
    <div class="cardView">
        <div class="cards" :style='{"margin":"0 0 20px 0","alignItems":"center","justifyContent":"center","display":"flex"}'>
			<div :style='{"margin":"0 10px","backgroundSize":"100% 100%","borderRadius":"4px","backgroundImage":"url(http://codegen.caihongy.cn/20220723/cd8eafb1ed9b452682e8fc1a968c4eef.png)","display":"flex"}' v-if="isAuth('pinkunhu','首页总数')">
				<div :style='{"background":"red"}'></div>
				<div :style='{"width":"190px","padding":"5px","alignItems":"center","flexDirection":"column","justifyContent":"center","display":"flex"}'>
					<div :style='{"margin":"5px 0","lineHeight":"24px","fontSize":"20px","color":"#333","fontWeight":"bold","height":"24px"}'>{{pinkunhuCount}}</div>
					<div :style='{"margin":"5px 0","lineHeight":"24px","fontSize":"16px","color":"#666","height":"24px"}'>孤寡与贫困户总数</div>
				</div>
			</div>
			<div :style='{"margin":"0 10px","backgroundSize":"100% 100%","borderRadius":"4px","backgroundImage":"url(http://codegen.caihongy.cn/20220723/cd8eafb1ed9b452682e8fc1a968c4eef.png)","display":"flex"}' v-if="isAuth('pinkunshenqing','首页总数')">
				<div :style='{"background":"red"}'></div>
				<div :style='{"width":"190px","padding":"5px","alignItems":"center","flexDirection":"column","justifyContent":"center","display":"flex"}'>
					<div :style='{"margin":"5px 0","lineHeight":"24px","fontSize":"20px","color":"#333","fontWeight":"bold","height":"24px"}'>{{pinkunshenqingCount}}</div>
					<div :style='{"margin":"5px 0","lineHeight":"24px","fontSize":"16px","color":"#666","height":"24px"}'>孤寡与贫困户申请总数</div>
				</div>
			</div>
        </div>
        <div style="display: flex;align-items: center;width: 100%;margin-bottom: 10px;">
            <el-card style="width: 33.3%;margin: 0 10px;" v-if="isAuth('pinkunhu','首页统计')">
                <div id="pinkunhuChart1" style="width:100%;height:400px;"></div>
            </el-card>
            <el-card style="width: 33.3%;margin: 0 10px;" v-if="isAuth('pinkunhu','首页统计')">
                <div id="pinkunhuChart2" style="width:100%;height:400px;"></div>
            </el-card>
            <el-card style="width: 33.3%;margin: 0 10px;" v-if="isAuth('pinkunshenqing','首页统计')">
                <div id="pinkunshenqingChart1" style="width:100%;height:400px;"></div>
            </el-card>
        </div>
    </div>
</div>
</template>
<script>
//3
import router from '@/router/router-static'
import * as echarts from 'echarts'
export default {
	data() {
		return {
            pinkunhuCount: 0,
            pinkunshenqingCount: 0,
		};
	},
  mounted(){
    this.init();
    this.getpinkunhuCount();
    this.pinkunhuChat1();
    this.pinkunhuChat2();
    this.getpinkunshenqingCount();
    this.pinkunshenqingChat1();
  },
  methods:{
    init(){
        if(this.$storage.get('Token')){
        this.$http({
            url: `${this.$storage.get('sessionTable')}/session`,
            method: "get"
        }).then(({ data }) => {
            if (data && data.code != 0) {
            router.push({ name: 'login' })
            }
        });
        }else{
            router.push({ name: 'login' })
        }
    },
    getpinkunhuCount() {
        this.$http({
            url: `pinkunhu/count`,
            method: "get"
        }).then(({
            data
        }) => {
            if (data && data.code == 0) {
                this.pinkunhuCount = data.data
            }
        })
    },

    pinkunhuChat1() {
      this.$nextTick(()=>{

        var pinkunhuChart1 = echarts.init(document.getElementById("pinkunhuChart1"),'dark-bold');
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
                pinkunhuChart1.setOption(option);
                  //根据窗口的大小变动图表
                window.onresize = function() {
                    pinkunhuChart1.resize();
                };
            }
        });
      })
    },

    pinkunhuChat2() {
      this.$nextTick(()=>{

        var pinkunhuChart2 = echarts.init(document.getElementById("pinkunhuChart2"),'dark-bold');
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
                pinkunhuChart2.setOption(option);
                  //根据窗口的大小变动图表
                window.onresize = function() {
                    pinkunhuChart2.resize();
                };
            }
        });
      })
    },





    getpinkunshenqingCount() {
        this.$http({
            url: `pinkunshenqing/count`,
            method: "get"
        }).then(({
            data
        }) => {
            if (data && data.code == 0) {
                this.pinkunshenqingCount = data.data
            }
        })
    },

    pinkunshenqingChat1() {
      this.$nextTick(()=>{

        var pinkunshenqingChart1 = echarts.init(document.getElementById("pinkunshenqingChart1"),'dark-fresh-cut');
        this.$http({
            url: "pinkunshenqing/group/shenqingshijian",
            method: "get",
        }).then(({ data }) => {
            if (data && data.code === 0) {
                let res = data.data;
                let xAxis = [];
                let yAxis = [];
                let pArray = []
                for(let i=0;i<res.length;i++){
                    xAxis.push(res[i].shenqingshijian);
                    yAxis.push(parseFloat((res[i].total)));
                    pArray.push({
                        value: parseFloat((res[i].total)),
                        name: res[i].shenqingshijian
                    })
                }
                var option = {};
                option = {
                    title: {
                        text: '孤寡与贫困户申请统计',
                        left: 'center'
                    },
                    tooltip: {
                      trigger: 'item',
                      formatter: '{b} : {c}'
                    },
                    xAxis: {
                        type: 'category',
                        boundaryGap: false,
                        data: xAxis
                    },
                    yAxis: {
                        type: 'value'
                    },
                    series: [{
                        data: yAxis,
                        type: 'line',
                        areaStyle: {},
                        smooth: true
                    }]
                };
                // 使用刚指定的配置项和数据显示图表。
                pinkunshenqingChart1.setOption(option);
                  //根据窗口的大小变动图表
                window.onresize = function() {
                    pinkunshenqingChart1.resize();
                };
            }
        });
      })
    },






  }
};
</script>
<style lang="scss" scoped>
    .cardView {
        display: flex;
        flex-wrap: wrap;
        width: 100%;

        .cards {
            display: flex;
            align-items: center;
            width: 100%;
            margin-bottom: 10px;
            justify-content: center;
            .card {
                width: calc(25% - 20px);
                margin: 0 10px;
                /deep/.el-card__body{
                    padding: 0;
                }
            }
        }
    }
</style>
