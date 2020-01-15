#!/usr/bin/python
#-*- coding:utf-8 -*-

from django.http import HttpResponse


def index(resquest):
    return HttpResponse("index");
