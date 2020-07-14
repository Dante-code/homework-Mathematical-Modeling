clc;clear;

load adult_dealt.csv;
label_y = adult_dealt(:,15);
eigvalues = adult_dealt(:,1:14);


train_label = label_y(1:20000);
train_data = eigvalues(1:20000,[2 4 6 7 13]);

model = libsvmtrain(train_label,train_data,'-h 0');
test_label = label_y(20001:30000);
test_data = eigvalues(20001:30000,[2 4 6 7 13]);

[predict_label,accuracy,dec_value] = libsvmpredict(test_label,test_data,model);
